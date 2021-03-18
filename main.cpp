#include <bits/stdc++.h>

int partition(int stg, int dr, int arr[]) {
    char mod = 'a';

    if(stg == dr) {
        return stg;
    }else {
        
        while(stg < dr) {
            if(arr[stg] > arr[dr]) {
                std:: swap(arr[stg], arr[dr]);
                if(mod == 'a') mod = 'b';
                else mod = 'a';
            }

            if(mod == 'a') {
                dr--;
            }else {
                stg++;
            }
        }

        return stg;
    }
}

void QS(int stg, int dr, int ar[]) {
    int k;

    if(stg < dr) {
        k = partition(stg, dr, ar);
        QS(stg, k - 1, ar);
        QS(k + 1, dr, ar);
    }
}

int main() {
    int n, vec[10001];

    std:: cin >> n;

    for(int i = 1; i <= n; i++) {
        std:: cin >> vec[i];
    }

    QS(1, n, vec);

    for(int i = 1; i <= n; i++) {
        std:: cout << vec[i] << ' ';
    }

    return 0;
}
