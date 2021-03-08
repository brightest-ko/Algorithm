#include<iostream>
#include<queue>
using namespace std;

#define MAX 20

int arr[MAX][MAX];
int checked[MAX][MAX];

struct Info {
	int y;
	int x;
};

Info start_, end_;
queue<Info> qu;

int main() {
	for (int y = 0;y < 16;y++) {
		for (int x = 0;x < 16;x++) {
			scanf("%1d", arr[y][x]);
			if (arr[y][x] == 2) {
				start_.y = y;
				start_.x = x;
			}else if (arr[y][x] == 3) {
				end_.y = y;
				end_.x = x;
				arr[y][x] = 1;
			}
		}
	}

}