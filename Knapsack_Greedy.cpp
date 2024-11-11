#include <iostream>
using namespace std;

double Profit(double arr[101][4], int n, int W)
{
    double TP = 0.0;

    while (W > 0)
    {
        double maxRatio = -1.0;
        int index = -1;

        for (int i = 0; i < n; ++i)
        {
            if (arr[i][2] != -1)
            {
                double currentRatio = arr[i][0] / arr[i][1];
                if (currentRatio > maxRatio)
                {
                    maxRatio = currentRatio;
                    index = i;
                }
            }
        }

        if (index == -1)
            break;

        if (arr[index][1] <= W)
        {
            TP += arr[index][0];
            W -= arr[index][1];
            arr[index][3] = 1.0;
        }
        else
        {
            TP += arr[index][0] * (W / arr[index][1]);
            arr[index][3] = W / arr[index][1];
            break;
        }

        arr[index][2] = -1;
    }

    return TP;
}

int main()
{
    int W, n;
    double arr[101][4];
    cout << "Enter num of items: ";
    cin >> n;
    cout << "Enter Weight: ";
    cin >> W;

    cout << "Enter P_W: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = arr[i][0] / arr[i][1];

        arr[i][3] = 0.0;
    }
    cout << "Profit to weight ratios are";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i][2] << " ";
    }

    double Maxprofit = Profit(arr, n, W);

    cout << "Usage of profit: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i][3] << " ";
    }
    cout << endl;

    cout << "Max profit: " << Maxprofit << endl;
}