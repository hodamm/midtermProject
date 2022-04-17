#include <bangtal.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
SceneID scene1;
ObjectID card[52], goButton1, goButton2, goButton3, stopButton, outButton, startButton, back[7], ruleButton, rule;
int sum;
int dealerSum;
const char* card_image[52] = {
	"As.jpeg",
	"Ad.jpeg",
	"Ah.jpeg",
	"Ac.jpeg",
	"2s.jpeg",
	"2d.jpeg",
	"2h.jpeg",
	"2c.jpeg",
	"3s.jpeg",
	"3d.jpeg",
	"3h.jpeg",
	"3c.jpeg",
	"4s.jpeg",
	"4d.jpeg",
	"4h.jpeg",
	"4c.jpeg",
	"5s.jpeg",
	"5d.jpeg",
	"5h.jpeg",
	"5c.jpeg",
	"6s.jpeg",
	"6d.jpeg",
	"6h.jpeg",
	"6c.jpeg",
	"7s.jpeg",
	"7d.jpeg",
	"7h.jpeg",
	"7c.jpeg",
	"8s.jpeg",
	"8d.jpeg",
	"8h.jpeg",
	"8c.jpeg",
	"9s.jpeg",
	"9d.jpeg",
	"9h.jpeg",
	"9c.jpeg",
	"10s.jpeg",
	"10d.jpeg",
	"10h.jpeg",
	"10c.jpeg",
	"Js.jpeg",
	"Jd.jpeg",
	"Jh.jpeg",
	"Jc.jpeg",
	"Qs.jpeg",
	"Qd.jpeg",
	"Qh.jpeg",
	"Qc.jpeg",
	"Ks.jpeg",
	"Kd.jpeg",
	"Kh.jpeg",
	"Kc.jpeg",
};

void end() {
	if (sum>21) {showMessage("Bust!!!You lose...");}
	else if (sum < dealerSum ) {showMessage("You lose...ㅜㅜ");}
	else if (sum == dealerSum) { showMessage("Draw"); }
	else {showMessage("You win!!!ㅎㅎ");}
	hideObject(goButton1);
	hideObject(goButton2);
	hideObject(goButton3);
	hideObject(stopButton);
}
void draw5() {
	srand((unsigned int)time(NULL));
	int d55 = (rand() + 33) % 52;
	ObjectID d5 = card[d55];
	locateObject(d5, scene1, 720, 500);
	showObject(d5);
	dealerSum += d55 / 4 + 1;
	if (dealerSum > 21) { showMessage ("You win!!!ㅎㅎ"); }
	else { end(); }
}
void draw4() {
	srand((unsigned int)time(NULL));
	int d44 = (rand() + 15) % 52;
	ObjectID d4 = card[d44];
	locateObject(d4, scene1, 690, 500);
	showObject(d4);
	dealerSum += d44 / 4 + 1;
	if (dealerSum < 17) { draw5(); }
	else if (dealerSum < 22) { end(); }
	else { showMessage("You win!!!ㅎㅎ"); }
}
void draw3() {
	srand((unsigned int)time(NULL));
	int d33 = (rand() + 11) % 52;
	ObjectID d3 = card[d33];
	locateObject(d3, scene1, 660, 500);
	showObject(d3);
	dealerSum += d33 / 4 + 1;
	if (dealerSum < 17) { draw4(); }
	else if (dealerSum < 22) { end(); }
	else { showMessage("You win!!!ㅎㅎ"); }
}
void draw2() {
	srand((unsigned int)time(NULL));
	int d22 = (rand() + 47) % 52;
	ObjectID d2 = card[d22];
	locateObject(d2, scene1, 630, 500);
	showObject(d2);
	if (d22 > 39) { d22 = 39; }
	dealerSum += d22 / 4 + 1;
	if (dealerSum < 17) { draw3(); }
	else if (dealerSum < 22) { end(); }
	else { showMessage("You win!!!ㅎㅎ"); }
}
void draw1() {
	srand((unsigned int)time(NULL));
	int d11 = (rand() + 24) % 52;
	ObjectID d1 = card[d11];
	locateObject(d1, scene1, 600,500);
	showObject(d1);
	if (d11 > 39) {d11 = 39;}
	dealerSum = d11 / 4 + 1;
}

void hand1() {
	srand((unsigned int)time(NULL));
	int  c11 = rand() % 52;
	ObjectID c1 = card[c11];
	locateObject(c1, scene1, 600, 100);
	showObject(c1);
	if (c11 > 39) {c11 = 39;}
	sum = c11 / 4 +1;
}
void hand2() {
	srand((unsigned int)time(NULL));
	int c22 = (rand() + 26) % 52;
	ObjectID c2 = card[c22];
	locateObject(c2, scene1, 630, 100);
	showObject(c2);
	if (c22 > 39) {c22 = 39;}
	sum += c22/4+1;
	if (sum > 21) { end(); }
}
void hand3() {
	srand((unsigned int)time(NULL));
	int c33 = (rand() + 2) % 52;
	ObjectID c3 = card[c33];
	locateObject(c3, scene1, 660, 100);
	showObject(c3);
	if (c33 > 39) {c33 = 39;}
	sum += c33/4+1;
	if (sum > 21) { end(); }
}
void hand4() {
	srand((unsigned int)time(NULL));
	int c44 = (rand() + 8) % 52;
	ObjectID c4 = card[c44];
	locateObject(c4, scene1, 690, 100);
	showObject(c4);
	if (c44 > 39) {c44 = 39;}
	sum += c44 / 4 + 1;
	if (sum > 21) { end(); }
}
void hand5() {
	srand((unsigned int)time(NULL));
	int c55 = (rand() + 1) % 52;
	ObjectID c5 = card[c55];
	locateObject(c5, scene1, 720, 100);
	showObject(c5);
	if (c55 > 39) {c55 = 39;}
	sum += c55/4+1;
	if (sum > 21) { end(); }
	else { 
		showMessage("히든룰!!5장의 카드를 받아 승리했습니다");
		hideObject(goButton1);
		hideObject(goButton2);
		hideObject(goButton3);
		hideObject(stopButton);
	}
}

void mouseCallback(ObjectID object, int x, int y, MouseAction) {
	if (object == startButton) {
		hideObject(startButton);
		showObject(goButton1);
		showObject(goButton2);
		showObject(goButton3);
		showObject(stopButton);
		for (int n = 0; n < 7; n++) {showObject(back[n]);}
		hand1();
		hand2();
		draw1();
	}
	else if (object == outButton) {endGame();}
	else if (object == goButton3) {
		hand3();
		hideObject(goButton3);
	}
	else if (object == goButton2) {
		hand4();
		hideObject(goButton2);
	}
	else if (object == goButton1) {hand5();}
	else if (object == stopButton) {draw2();}
	else if (object == ruleButton) {showObject(rule);}
	else if (object == rule) { hideObject(rule); }
}



int main() {
	setMouseCallback(mouseCallback);
	scene1 = createScene("BlackJack", "background.jpg");
	goButton1 = createObject("go.jpg");
	goButton2 = createObject("go.jpg");
	goButton3 = createObject("go.jpg");
	ruleButton = createObject("rule.jpg");
	rule = createObject("rules.jpg");
	stopButton = createObject("stop.jpg");
	outButton = createObject("out.jpg");
	startButton = createObject("start.jpg");
	for (int i = 0; i < 52; i++) {card[i] = createObject(card_image[i]);}
	for (int n = 0; n < 7; n++) {back[n] = createObject("뒷면.jpg");}
	locateObject(startButton, scene1, 500, 100);
	locateObject(outButton, scene1, 0, 600);
	locateObject(goButton1, scene1, 300, 30);
	locateObject(goButton2, scene1, 300, 30);
	locateObject(goButton3, scene1, 300, 30);
	locateObject(stopButton, scene1, 900, 30);
	locateObject(back[0], scene1, 720, 100);
	locateObject(back[1], scene1, 690, 100);
	locateObject(back[2], scene1, 660, 100);
	locateObject(back[3], scene1, 720, 500);
	locateObject(back[4], scene1, 690, 500);
	locateObject(back[5], scene1, 660, 500);
	locateObject(back[6], scene1, 630, 500);
	locateObject(ruleButton, scene1, 100, 600);
	locateObject(rule, scene1, 0, 0);
	showObject(caution);
	showObject(startButton);
	showObject(outButton);
	showObject(ruleButton);
	startGame(scene1);
}
