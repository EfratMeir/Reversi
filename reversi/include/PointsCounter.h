/*
 * PointsCounter.h
 */

#ifndef POINTSCOUNTER_H_
#define POINTSCOUNTER_H_

/**
 * this class responsible for counting how many black and white
 * points are on the board
 */
class PointsCounter {
public:
	/**
	 * constructor
	 */
	PointsCounter();
	/**
	 * adds one to the count of the player with the sign given
	 */
	void add_one(char sign);

	/**
	 * decreas one from he count of the player with the sign given
	 */
	void minus_one(char sign);

	/**
	 * adds to the counter of the player with the sign given
	 * @how much - how many to aadd
	 * @sign - sign of the player adding to
	 */
	void add(int how_much, char sign);

	/**
	 * decreases from the counter of the player with the sign given
	 * @how much - how many to added
	 * @sign - sign of the player adding to
	 */
	void minus(int how_much, char sign);

	//getters and setters:
	int getBlackCount() const {
		return black_count;
	}

	int getWhiteCount() const {
		return white_count;
	}


private:
	//class members:
	int white_count;
	int black_count;
};

#endif /* POINTSCOUNTER_H_ */
