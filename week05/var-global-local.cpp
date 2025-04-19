int i = 3;
int j = 4;
void setup() {
	int j = 5;
	Serial.begin(115200);
	Serial.println();
	if (j > 3) {
		int i = j + 1;
		Serial.println(i);
	}
	Serial.println(i);
	Serial.println(j);
}

void loop() {

}