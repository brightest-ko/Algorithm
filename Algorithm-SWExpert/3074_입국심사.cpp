#include <stdio.h>

int main(void) {
	int T;
	setbuf(stdout, NULL);
	scanf("%d\n", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int time[100001];
		long long max = 0;
		//각 심사대에서 심사하는데 걸리는 시간
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &time[i]);
			if (time[i] > max)
				max = time[i];//심사대에서 최대로 걸리는 시간 기록
		}

		long long time1 = 0;
		long long time2 = max * m;//최대로 걸릴 수 있는 시간 : 가장 오래 걸리는 심사대 * 사람수
		long long mid;
		long long min = max * m;//최대로 걸릴 수 있는 시간으로 초기화 : 가장 오래 걸리는 심사대 * 사람수

		while (time1 <= time2)//이진탐색
		{
			//mid==현재 진행된 시간
			mid = (time1 + time2) / 2;
			long long answer = 0;

			for (int i = 0; i < n; i++)
			{
				answer = answer + (mid / time[i]);//현재 mid만큼 진행 되었을 때, 각 심사대에서 심사한 사람 수
			}

			if (answer < m)//아직 심사해야할 사람이 남았으면 시간이 더 필요함
			{
				time1 = mid + 1;
			}
			else//사람수보다 더 많은 사람을 처리할 수 있으면, 시간이 남으므로, 시간을 줄인다
			{
				if (min > mid)
					min = mid;
				time2 = mid - 1;
			}
		}
		printf("#%d %lld\n", test_case, min);
	}
	return 0;
}

//출처: https://ddoublej.tistory.com/317 [컴퓨터공부하기]