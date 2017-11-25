///*
// * testers.cpp
// *
// *  Created on: Nov 5, 2017
// *      Author: efrat
// */
//
//#include "testers.h"
//#include <iostream>
//#include "Board.h"
//#include "Point.h"
//#include "MovesCalculator.h"
//#include <list>
//#include <vector>
//using namespace std;
//
//testers::testers() {
//	// TODO Auto-generated constructor stub
//
//}
//
//
//
//
//
///*
// *  Created on: Oct 28, 2017
// *      Author: Efrat Meir
// *      user name meirefr
// *      ID 201543253
// */
//
//
//
//void test() {
//	Board b = Board(8,8);
//	vector<Point> vp;
//	MovesCalculator moves = MovesCalculator();
//	//checkRight TEST:
//	moves.checkLeft(b, b.parr[4][4], 'X', vp);
//		int x = vp[0].get_x();
//		int y = vp[0].get_y();
//		if (x != 4 || y != 5) {
//			cout << "check right failed";
//		}
//
//	//checkLeft TEST:
//	moves.checkLeft(b, b.parr[3][3], 'X', vp);
//	 x = vp[0].get_x();
//	 y = vp[0].get_y();
//	if (x != 3 || y != 2) {
//		cout << "check left failed";
//	}
//
//	//checkDown TEST:
//	moves.checkLeft(b, b.parr[4][4], 'X', vp);
//	 x = vp[0].get_x();
//	 y = vp[0].get_y();
//	if (x != 5 || y != 4) {
//		cout << "check down failed";
//	}
//
//	//checkUp TEST:
//		moves.checkLeft(b, b.parr[3][3], 'X', vp);
//		 x = vp[0].get_x();
//		 y = vp[0].get_y();
//		if (x != 2 || y != 3) {
//			cout << "check up failed";
//		}
//
//
//		//check UP-RIGHT
//		Point p = Point(5, 3, 'X');
//		b.setPoint(p);
//		moves.checkLeft(b, b.parr[4][4], 'X', vp);
//			 x = vp[0].get_x();
//			 y = vp[0].get_y();
//			if (x != 3 || y != 5) {
//				cout << "check up right failed";
//			}
//}
