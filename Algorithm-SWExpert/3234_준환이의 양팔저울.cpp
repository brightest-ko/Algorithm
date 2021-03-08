#include <iostream>
using namespace std;

#define MAX 15
int w[MAX];
int cnt;

int test_case;
int n;

void perm(int step, int l, int r) {
	//cout << l << " " << r << endl;

	if (step == n) {
		// System.out.println(Arrays.toString(w));
		/*
		for (int i = 0;i < n;i++) {
			cout << w[i] << " ";
		}
		cout << endl;
		*/
		cnt++;
	}
	else {
		for (int i = step; i < n; i++) {
			int temp = w[step];
			w[step] = w[i];
			w[i] = temp;

			// ���� �ܰ� ���ȣ��
			perm(step + 1, l + w[step], r); // ������ ���ʿ� w[step]�߸� �÷� ���� ���ȣ��
			if (l >= r + w[step]) {
				perm(step + 1, l, r + w[step]); // ������ �����ʿ� w[step]�߸� �÷� ���� ���ȣ��
			}
			temp = w[step];
			w[step] = w[i];
			w[i] = temp;

		}
	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &test_case);
	for (int T = 1;T <= test_case;T++) {
		scanf("%d", &n);
		for (int i = 0;i < n;i++) {
			scanf("%d", &w[i]);
		}

		cnt = 0;
		perm(0, 0, 0);
		printf("#%d %d\n", T, cnt);
	}
	return 0;
}