#include <bits/stdc++.h>
using namespace std;

// The hien toa do (x,y) , trang thai cua moi o vuong tren ban co qua bien count
struct data
{
    int x, y, count;
    data()
    {
        count=0;
    }
    data(int _x, int _y, int _count)
    {
        x = _x; y = _y; count = _count;
    }
};

int main()
{
    queue <data> Q;
    int n, x , y , des_x , des_y;


    /** Voi x, y la do dai buoc di cua quan Ma theo truc Oxy
        mot buoc di hop le cua quan Ma se thoa man |x| + |y| = 3
        Ta co 2 mang luu tru nhung gia tri cua x, y.
    */
    int X[8]={-2,-2,-1,-1,1,1,2,2};
    int Y[8]={-1,1,-2,2,-2,2,-1,1};

    cout << "Kich thuoc ban co: ";
    cin >> n;

    int board[n][n]; // Mang 2 chieu, the hien ma tran ban co

    cout << "Source: ";
    cin >> x >> y;
    x += 1;
    y += 1;

    cout << "Destination: ";
    cin >> des_x >> des_y;
    des_x += 1;
    des_y += 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            board[i][j]=0;

    Q.push(data(x,y,0));
    board[x][y]=1;

    // Thuat toan tim duong di BFS
    while (!Q.empty())
    {
        data tmp = Q.front();
        Q.pop();
        for (int i=0; i<8; i++)
        {
            int next_x = X[i] + tmp.x;
            int next_y = Y[i] + tmp.y;
            if (1 <= next_x && next_x <= n && 1 <= next_y && next_y <= n && board[next_x][next_y] == 0)
            {
                board[next_x][next_y] = 1;
                Q.push(data(next_x, next_y, tmp.count + 1));
                if (next_x == des_x && next_y == des_y)
                {
                    cout << "So buoc thuc hien nho nhat la: "  << tmp.count + 1;
                    return 0;
                }
            }
        }
    }
    cout << "Khong thuc hien duoc buoc di den dich.";
    return 0;
}

