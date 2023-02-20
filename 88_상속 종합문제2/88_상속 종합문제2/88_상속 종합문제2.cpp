// 88_상속 종합문제2

// Q3. 상속과 가상함수를 활용해 중복되는 코드를 줄여 보시오.
/*
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

enum LogLevels {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	FATAL
};

const char* const LEVEL_HEADINGS[] = {
	"DEBUG", "INFO", "WARNING", "ERROR", "FATAL"
};

class FileLogger {
public:
	FileLogger(int minLevel, const string &fileName) : minLevel(minLevel) {
		logFile = fopen(fileName.c_str(), "a");
	}
	~FileLogger() {
		fclose(logFile);
	}

	void Log(const string &s, int level) {
		if (level >= minLevel)
			fprintf(logFile, "[%s] %s\n", LEVEL_HEADINGS[level], s.c_str());
	}

	int GetMinLevel() const { return minLevel; }

private:
	int minLevel;
	FILE *logFile;
};

class ConsoleLogger {
public:
	ConsoleLogger(int minLevel) : minLevel(minLevel) {}

	void Log(const string &s, int level) {
		if (level >= minLevel)
			printf("[%s] %s\n", LEVEL_HEADINGS[level], s.c_str());
	}

	int GetMinLevel() const { return minLevel; }

private:
	int minLevel;
};

int main() {
	ConsoleLogger c(LogLevels::WARNING);
	c.Log("abc", LogLevels::ERROR);
	c.Log("def", LogLevels::INFO);
	c.Log("ghi", LogLevels::WARNING);

	FileLogger f(LogLevels::DEBUG, "log.txt");
	f.Log("abc", LogLevels::ERROR);
	f.Log("def", LogLevels::INFO);
	f.Log("ghi", LogLevels::WARNING);
}
*/

// Q3. 정답

#include <iostream>
#include <stdio.h>
#include <string>
#define _CRT_SECURE_NO_WARINGS

using namespace std;


enum LogLevels {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	FATAL
};

const char* const LEVEL_HEADINGS[] = {
	"DEBUG", "INFO", "WARNING", "ERROR", "FATAL"
};

class Logger {
public:
	Logger(int minLevel) : minLevel(minLevel) { };
	virtual ~Logger() { };
	// Log 함수는 두 클래스 모두 역할이 비슷하나 그 세부 내용이 조금씩 다르므로 가상 함수를 써서 오버라이딩을 하면 좋겠다.
	virtual void Log(const string& s, int level) {
		if (level >= minLevel)
			printLog(s, level);
	}
	// GetMinLevel 함수는 완전 똑같은 함수이므로 부모 클래스에서 해결한다.
	const int GetMinLevel() const { return minLevel; }


protected:
	int minLevel;
	virtual void printLog(const string& s, int level) = 0;
};

class FileLogger : public Logger{
public:
	FileLogger(int minLevel, const string& fileName) : Logger(minLevel) {
		logFile = fopen(fileName.c_str(), "a");
	}
	~FileLogger() {
		fclose(logFile);
	}

	void printLog(const string& s, int level) {
		fprintf(logFile, "[%s] %s\n", LEVEL_HEADINGS[level], s.c_str());
	}

private:
	FILE* logFile;
};

class ConsoleLogger : public Logger{
public:
	ConsoleLogger(int minLevel) : Logger(minLevel) {}

	void printLog(const string& s, int level) {
		printf("[%s] %s\n", LEVEL_HEADINGS[level], s.c_str());
	}

};

void testLogger(Logger* l) {
	
	l->Log("abc", LogLevels::ERROR);
	l->Log("def", LogLevels::INFO);
	l->Log("ghi", LogLevels::WARNING);
}

int main() {
	Logger* l[2] = { new ConsoleLogger(LogLevels::WARNING), new FileLogger(LogLevels::DEBUG, "log.txt") };

	for (int i = 0; i < 2; i++) {
		testLogger(l[i]);
	}

	for (int i = 0; i < 2; i++) {
		delete l[i];
	}
	/*
	ConsoleLogger c(LogLevels::WARNING); 
	c.Log("abc", LogLevels::ERROR);
	c.Log("def", LogLevels::INFO);
	c.Log("ghi", LogLevels::WARNING);

	FileLogger f(LogLevels::DEBUG, "log.txt");
	f.Log("abc", LogLevels::ERROR);
	f.Log("def", LogLevels::INFO);
	f.Log("ghi", LogLevels::WARNING);
	*/
}