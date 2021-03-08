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
		//�� �ɻ�뿡�� �ɻ��ϴµ� �ɸ��� �ð�
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &time[i]);
			if (time[i] > max)
				max = time[i];//�ɻ�뿡�� �ִ�� �ɸ��� �ð� ���
		}

		long long time1 = 0;
		long long time2 = max * m;//�ִ�� �ɸ� �� �ִ� �ð� : ���� ���� �ɸ��� �ɻ�� * �����
		long long mid;
		long long min = max * m;//�ִ�� �ɸ� �� �ִ� �ð����� �ʱ�ȭ : ���� ���� �ɸ��� �ɻ�� * �����

		while (time1 <= time2)//����Ž��
		{
			//mid==���� ����� �ð�
			mid = (time1 + time2) / 2;
			long long answer = 0;

			for (int i = 0; i < n; i++)
			{
				answer = answer + (mid / time[i]);//���� mid��ŭ ���� �Ǿ��� ��, �� �ɻ�뿡�� �ɻ��� ��� ��
			}

			if (answer < m)//���� �ɻ��ؾ��� ����� �������� �ð��� �� �ʿ���
			{
				time1 = mid + 1;
			}
			else//��������� �� ���� ����� ó���� �� ������, �ð��� �����Ƿ�, �ð��� ���δ�
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

//��ó: https://ddoublej.tistory.com/317 [��ǻ�Ͱ����ϱ�]