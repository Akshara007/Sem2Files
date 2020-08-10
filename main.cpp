#include <string>
#include <vector>
#include<iostream>
#include <math.h>   
using namespace std;

// Given base = B create a number line ;
// etc if B = 2; we have [0,1,10,11];
// etc if B = 5; we have [0,1,2,3,4,10,11,12,13,14]
vector<int> base_number_line(int b) {
    vector<int> arr;
   
    int c = 0;
    int a = 0;
    while (c < b)
    {
        a = 0;
        while (a < b) {
            arr.push_back(10 * c + a);
            a++;
        }
        c++;
    }
    return arr;
}


// String to vector<int>
vector<int> string_to_vector(string I) {
    vector<int> integer;
    int i = 0;
    for (unsigned int j = 0; j < I.size(); j++) {
        i = (int)I[j];
        integer.push_back(i-48);
    }
    return integer;
}

string vector_to_string(vector<int> vec)
{
    char i;
    string s = "";
    for (int j = 0; j <vec.size(); j++)
    {
        s = s + to_string(vec[j]);
    }
    return s;
}

vector<int> school_addition(vector<int> i1, vector<int> i2, int base)
{
    reverse(i1.begin(), i1.end());
    reverse(i2.begin(), i2.end());
    int j = 0;
    int s = 0;
    int c = 0;
    vector<int> base_line = base_number_line(base);
    vector<int> result;
    int max_size = max(i1.size(), i2.size());
    int min_size = min(i1.size(), i2.size());

    // Ensure both vectors are of same size 
    if (i1.size() > i2.size()) {
        for (int i = 0; i < max_size - min_size; i++) {
            i2.push_back(0);
        }
    }
    else if (i1.size() < i2.size()) {
        for (int i = 0; i < max_size - min_size; i++) {
            i1.push_back(0);
        }
    }
    while (j < max_size || c >= 1) {
        if (j < max_size) {      
            s = base_line[i1[j] + i2[j] + c];
            
            if (s >= 10) {
                result.push_back(s % 10);
                c = 1;
            }
            else {
                result.push_back(s);
                c = 0;
            }
            j++;
        }
        else if (j == max_size) {
            s = base_line[c];
            result.push_back(s);
            break;
        }
    }
    //result is reversed here itself
    reverse(result.begin(), result.end());
    return result;
}

vector<int> school_subtraction(vector<int> i1, vector<int> i2, int base) {
    // Implement school subtraction for karatsuba, i1 should always be the greater number;
    reverse(i1.begin(), i1.end());
    reverse(i2.begin(), i2.end());

    int j = 0;
    int c = 0;

    vector<int> result;
    int max_size = i1.size();
    int min_size = i2.size();
    if (max_size > min_size) {
        for (int i = 0; i < max_size - min_size; i++) {
            i2.push_back(0);
        }
    }

    while (j < max_size || c >= 1) {
        if (i1[j] - c < i2[j]) {
            result.push_back(i1[j] + base - i2[j] - c);
            c = 1;
        }
        else {
            result.push_back(i1[j] - i2[j] - c);
            c = 0;
        }
        j++;
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<int> school_multiplication(vector<int> i1, vector<int> i2, int base)
{
    vector<int> c, result, temp;
    int val;
    reverse(i1.begin(), i1.end());
    reverse(i2.begin(), i2.end());

    if (i2.size() > i1.size())
    {
        i1.swap(i2);
    }
    for (int i = 0; i < i2.size(); i++)
    {
        c.clear();
        c.push_back(0);
        for (int j = 0; j < i1.size(); j++)
        {
            val = i1[j] * i2[i] + c[j];
            if (val >= base)
            {
                temp.push_back((val) % base);
                c.push_back((val - ((val) % base)) / base);
            }
            else
            {
                temp.push_back(val);
                c.push_back(0);
            }
        }
        if (c.back() != 0)
            temp.push_back(c.back());
        for (int k = 0; k < i; k++)
        {
            temp.insert(temp.begin(), 0);
        }
        reverse(temp.begin(), temp.end());
        result = school_addition(temp, result, base);
        temp.clear();
    }
    return result;
}

vector<int> Karatsuba_Multiplication(vector<int> vec1, vector<int> vec2, int base)
{
    vector<int> a1, a0, b1, b0, c0, c1, c2, d;
    int n = max(vec1.size(), vec2.size());
    if (n = 1)
    {
        return school_multiplication(vec1, vec2, base);
    }
    //Separation point
    if (n % 2 == 1)
    {
        n = (n + 1) / 2;
    }
    else
        n = n / 2;
    //Vec1 Separation
    if (vec1.size() <= n)
    {
        a1.push_back(0);
        a0 = vec1;
    }
    else
    {
        for (int i = 0; i < vec1.size() - n; i++)
        {
            a1.push_back(vec1[i]);
            reverse(a1.begin(), a1.end());
        }
        for (int i = vec1.size(); i < n; i++)
        {
            a0.push_back(vec1[i]);
            reverse(a0.begin(), a0.end());
        }
    }
    //Vec2 Separation
    if (vec2.size() <= n)
    {
        b1.push_back(0);
        b0 = vec2;
    }
    else
    {
        for (int i = 0; i < vec2.size() - n; i++)
        {
            b1.push_back(vec2[i]);
            reverse(b1.begin(), b1.end());
        }
        for (int i = vec2.size(); i < n; i++)
        {
            b0.push_back(vec2[i]);
            reverse(b0.begin(), b0.end());
        }
    }
    c0 = school_multiplication(a0, b0, base);
    c1 = school_multiplication(a1, b1, base);
    c2 = school_multiplication(school_subtraction(a0, a1, base), school_subtraction(b0, b1, base), base);
    //(c1*base^2n)+((c1-c2-c0)*base^(n))+(c0)
    return school_addition(school_multiplication(school_subtraction(school_addition(school_addition(school_multiplication(c1, int_to_vector(int(pow(base, 2 * n)), base), base), c0, base), c1, base), c2, base), int_to_vector(int(pow(*base, n)), base), base), c0, base);

}


int main()
{
    string input;
    string delimiter = " ";

    getline(cin, input);
    string I1 = input.substr(0, input.find(delimiter));
    input.erase(0, input.find(delimiter) + delimiter.length());

    string I2 = input.substr(0, input.find(delimiter));
    input.erase(0, input.find(delimiter) + delimiter.length());

    string B = input.substr(0, input.find(delimiter));
    int base = stoi(B);

    vector<int> s_prod= school_multiplication(string_to_vector(I1), string_to_vector(I2),base);
    vector<int> s_sum = school_addition(string_to_vector(I1), string_to_vector(I2), base);
    string str_sum = vector_to_string(s_sum);
    string str_prod = vector_to_string(s_prod);
    cout<<str_sum<<" "<<str_prod<<endl;
    return 1;
}
