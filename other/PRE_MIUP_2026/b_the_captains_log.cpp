#include <bits/stdc++.h>

std::unordered_map<std::string, int> WEEK_DAYS = 
{
    {"Mon", 0},
    {"Tue", 1},
    {"Wed", 2},
    {"Thu", 3},
    {"Fri", 4},
    {"Sat", 5},
    {"Sun", 6},
};

int MAX_MINUTES = 7 * 24 * 60;

void solve()
{
    std::string start_week_day;
    std::string start_time;

    std::string end_week_day;
    std::string end_time;

    std::cin >> start_week_day >> start_time;
    std::cin >> end_week_day >> end_time;

    int start_day = WEEK_DAYS[start_week_day];
    int start_hour = std::stoi(start_time.substr(0, 2));
    int start_minute = std::stoi(start_time.substr(3, 2));

    int end_day = WEEK_DAYS[end_week_day];
    int end_hour = std::stoi(end_time.substr(0, 2));
    int end_minute = std::stoi(end_time.substr(3, 2));

    int start_time_in_minutes = (start_day * 24 * 60) + (start_hour * 60) + start_minute;
    int end_time_in_minutes = (end_day * 24 * 60) + (end_hour * 60) + end_minute;

    int time_taken = end_time_in_minutes - start_time_in_minutes;
    if (time_taken <= 0)
        time_taken = MAX_MINUTES + time_taken;
    
    int time_taken_minutes = time_taken % 60;
    int time_taken_hours = (time_taken / 60) % 24;
    int time_taken_days = time_taken / (60 * 24);

    if (time_taken_days > 0)
    {
        std::cout << time_taken_days << " day";
        if (time_taken_days > 1)
            std::cout << "s";
    }

    if (time_taken_hours > 0)
    {
        if (time_taken_days > 0 && time_taken_minutes == 0)
            std::cout << " and ";
        else if (time_taken_days > 0)
            std::cout << ", ";

        std::cout << time_taken_hours << " hour";
        if (time_taken_hours > 1)
            std::cout << "s";
    }

    if (time_taken_minutes > 0)
    {
        if (time_taken_hours > 0 ^ time_taken_days > 0)
            std::cout << " and ";
        else if (time_taken_hours > 0)
            std::cout << ", ";

        std::cout << time_taken_minutes << " minute";
        if (time_taken_minutes > 1)
            std::cout << "s";
    }

    std::cout << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}