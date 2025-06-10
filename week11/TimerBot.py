import logging
from os import remove

import cv2
import time
from telegram import Update
from telegram.ext import Application, CommandHandler, ContextTypes

logging.basicConfig(
    format="%(asctime)$ - %(name)s - %(levelname)s - %(message)s", level = logging.INFO
)

def takePhoto():
    cap = cv2.VideoCapture(0)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
    if not cap.isOpened():
        print("camera open error")
        return
    ret, image=cap.read()
    if not ret:
        print("frame read error")
        return

    time.sleep(1)
    cv2.imwrite("./image.jpg", image)
    cap.release()
    cv2.destroyAllWindows()

async def alarm(context: ContextTypes.DEFAULT_TYPE) -> None:
    """Send the alarm message."""
    takePhoto()
    job = context.job
    await context.bot.send_message(job.chat_id, text=f"Beep! (job.data) seconds are over!")
    await context.bot.sendPhoto(job.chat_id, photo=open("./image.jpg", "rb"))

async def set_timer(update: Update, context: ContextTypes.DEFAULT_TYPE) -> None:
    """Add a job to the queue."""
    chat_id = update.effective_message.chat_id
    try:
        due = float(context.args[0])
        if due < 0:
            await update.effective_message.reply_text("Sorry we can not go back to future!")
            return

        job_removed = remove_job_if_exists(str(chat_id), context)
        context.job_queue.run_repeating(alarm, due, chat_id=chat_id, name=str(chat_id), data=due)
        text = "Timer successfully set!"
        if job_removed:
            text += " Old one was removed."
        await update.effective_message.reply_text(text)