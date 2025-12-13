#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

int count_leap_years(int year) {
    int ans = year / 4;
    ans -= year / 100;
    ans += year / 400;

    return ans;
}

int leap_years(int start_year, int end_year) {
    return count_leap_years(end_year) - count_leap_years(start_year - 1);
}

void solve(int cs) {
    cout << "Case " << cs << ": ";

    string start_month, end_month;
    int start_date, start_year, end_date, end_year;
    char dummy;
    cin >> start_month >> start_date >> dummy >> start_year;
    cin >> end_month >> end_date >> dummy >> end_year;

    if(start_month != "January" && start_month != "February") {
        start_year++;
    }
    if(end_month != "January" || (end_month != "February" && end_date < 29)) {
        end_year++;
    }

    cout << leap_years(start_year, end_year) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, cs = 0;
    cin >> t;
    while(t--) {
        solve(++cs);
    }
    return 0;
}