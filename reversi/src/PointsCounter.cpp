/*
 * PointsCounter.cpp
 */

#include <PointsCounter.h>

PointsCounter::PointsCounter() {
	black_count = 0;
	white_count = 0;
}

void PointsCounter::add_one(char sign) {
	if (sign == 'X') {
		black_count++;
	}
	if (sign == 'O') {
		white_count++;
	}
}

void PointsCounter::minus_one(char sign) {
	if (sign == 'X') {
		black_count--;
	}
	if (sign == 'O') {
		white_count--;
	}
}

void PointsCounter::add(int how_much, char sign) {
	for (int i = 0; i < how_much; i++) {
		add_one(sign);
	}
}

void PointsCounter::minus(int how_much, char sign) {
	for (int i = 0; i < how_much; i++) {
		minus_one(sign);
	}
}
