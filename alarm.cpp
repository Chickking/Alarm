/***************************************************************************
    This file is part of alarm
    Copyright (C) 2018 Victor Huang
	
	Current version: 0.0.1alpha

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***************************************************************************/

/*
在 Windows 上编译，需要添加 '-lwinmm' 参数。
对于 Dev-C++，点选“工具[T]”->“编译选项[C]“，选中”编译时加入以下命令“，在文本框中加上”-lwinmm“(不带引号)。 
*/

#include <cstdio>
#include <ctime>
#include <cstdlib>
#ifdef WIN32
	#include <windows.h>
	#include<mmsystem.h>
	#pragma comment(lib, "WINMM.LIB")
	#define sleep(x) Sleep(1000*x)
	#define ring PlaySound(TEXT("alarm.wav"),0,SND_FILENAME);;
#else
	#include <unistd.h>
#endif

#ifdef __APPLE__
	#define ring system("afplay alarm.wav");
#endif

#ifdef unix
	#define ring system("mplayer alarm.wav");
#endif

int h, m, s, ch, cm, cs, deltaT;

bool isTomorrow(int h, int m, int s, int ch, int cm, int cs) {
	if (h < ch)
		return true;
	else if (h == ch) {
		if (m < cm)
			return true;
		else if (m == cm) {
			if (s <= cs)
				return true;
		}
	}
	return false;
}

int delta_time(int h, int m, int s, int ch, int cm, int cs) {
	int dT;
	if (isTomorrow(h, m, s, ch, cm, cs)) {
		dT = ((24 - ch) + h) * 3600 + (m - cm) * 60 + (s - cs);
	}
	else {
		dT = (h - ch) * 3600 + (m - cm) * 60 + (s - cs);
	}
	return dT;
}

void getTime() {
	struct tm *time_container;
	time_t lt;
	lt = time(NULL);
	time_container = localtime(&lt);
	ch = time_container->tm_hour;
	cm = time_container->tm_min;
	cs = time_container->tm_sec;
}

int main() {
	getTime();
	printf("当前时间是: %02d:%02d:%02d \n", ch, cm, cs);
	printf("请按 H:mm:ss 的格式输入时间: \n");
	scanf("%d:%d:%d", &h, &m, &s);
	printf("您输入的时间是: %02d:%02d:%02d\n", h, m, s);
	getTime();
	deltaT = delta_time(h, m, s, ch, cm, cs);
	printf("等待时间戳为: %d\n", deltaT);
	sleep(deltaT);
	while (true) {
		ring;
		sleep(2);
	}
	return 0;
}