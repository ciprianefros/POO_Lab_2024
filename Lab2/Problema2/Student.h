#pragma once
#include <cstring>

class Student {
	private:
		char nume[20];
		float Math;
		float English;
		float History;
	public:
		void setName(const char nume[20]);
		char* getName();
		void setMath(float MathGrade);
		float getMath();
		void setEnglish(float EnglishGrade);
		float getEnglish();
		void setHistory(float HistoryGrade);
		float getHistory();
		float getAverage();
};		