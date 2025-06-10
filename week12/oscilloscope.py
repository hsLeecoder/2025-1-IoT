#Data Format
#CO2 Data0
#THL Temperature Data0, Humidity Data1, Illumination Data2, Battery Data3

import sys
import tos
import datatime
import threading

AM_OSCILLOSCOPE = 0x16

class OscilloscopeMsg(tos.Packet):
    def __init__(self.packet = None):
        tos.Packet.__init__(self,
                            [('srcID', 'int', 2),
                             ('seqNo', 'int', 4),
                             ('type', 'int', 2),
                             ('Data0', 'int', 2),
                             ('Data1', 'int', 2),
                             ('Data2', 'int', 1),
                             ('Data3', 'int', 1),
                             ('Data4', 'int', 2),
                             ],
                             packet)
if '-h' in sys.argv:
    print "Usage:", sys.argv[0], "serial@/dev/ttyUSB0:57600"
    sys.exit()

am = tos.AM()

while True:
    p = am.read()
    msg = OscilloscopeMsg(p.data)
    print p

###### THL Logic #######
    if msg.type == 2:
        battery = msg.Data4

        illumi = int(msg.Data2)+ int(msg.Data3*256)
        illumi = illumi
        humi = -2.0468 + (0.0367*msg.Data1) + (-1.5955*0.000001)*msg.Data1*mag.Data1
        temp = -(39.6) + (msg.Data0 * 0.01)
        try:
            with conn.cursor() as curs:
                Now = datatime.datatime.now()
                sql = """insert into JB_Sensor_THL(NODE_ID, SEQ, TEMPERATURE, HUMIDITY, ILLUMIANTION, REGDATE)

                values(%s, %s, %s, %s, %s, %s)"""
                curs.execute(sql,(msg,srcID,msg,seqNo,temp,humi,illumi,Now))
                conn.commit()
        except all, e:
            print e.args
            conn.close()
        print "id:", msg.srcID, " Count : ", msg.seqNo, \
                "Temperature: ", temp, "Humidity: ", humi, "Illumination: ", illumi, "Battery: ", battery






