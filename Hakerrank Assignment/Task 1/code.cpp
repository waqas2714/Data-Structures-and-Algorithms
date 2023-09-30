#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

int nonDivisibleSubset(int k, vector<int> s)
{
    cout << "HELLO WORLD!!!";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    bool isFirstTry = true, isInputCorrect = false;
    int n, k;
    vector<string> first_multiple_input;
    cout << "Enter n and k: \n";
    while (!isInputCorrect)
    {
        if (!isFirstTry)
        {
            cout << "n must be such that 1<= n <= 10^5 and k must be such that 1<= k <= 100\nPlease enter a correct input:\n";
            getline(cin, first_multiple_input_temp);
        }
        else
        {
            getline(cin, first_multiple_input_temp);
        }

        first_multiple_input = split(rtrim(first_multiple_input_temp));

        n = stoi(first_multiple_input[0]);
        if (n >= 1 && n <= (10 * 10 * 10 * 10 * 10))
        {
        }
        else
        {
            isFirstTry = false;
            continue;
        }

        k = stoi(first_multiple_input[1]);
        if (k >= 1 && k <= 100)
        {
        }
        else
        {
            isFirstTry = false;
            continue;
        }

        isInputCorrect = true;
    }

    isInputCorrect = false;
    vector<int> s(n);

    while (!isInputCorrect)
    {
        cout << "Give the " << n << " elements of the array.\n";

        string s_temp_temp;
        getline(cin, s_temp_temp);

        vector<string> s_temp = split(rtrim(s_temp_temp));

        if (s_temp.size() < n)
        {
            cout << "Please provide at least " << n << " numbers\n";
            continue;
        }


        for (int i = 0; i < n; i++)
        {
            int s_item = stoi(s_temp[i]);

            s[i] = s_item;
        }

        set<int> uniqueElements; // Use a set to store unique elements
        bool isUnique = true;
        for (int i = 0; i < n; i++)
        {
            if (uniqueElements.find(s[i]) != uniqueElements.end())
            {
                isUnique = false;
            }
            uniqueElements.insert(s[i]);
        }

        if (!isUnique)
        {
            cout << "The array contains duplicate elements.\n";
            continue;
        }

        // cout << "The array contains: ";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << s[i] << " ";
        // }

        isInputCorrect = true;
    }

    int result = nonDivisibleSubset(k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
