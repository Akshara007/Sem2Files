// Team details: PG, Workshop(Wednesday Online, 12pm-1pm)
// 1. Anh Quoc Vo (a1816541)
// 2. Akshara Gurudutt (a1807651)


#include <iostream>
#include <string>
#include <vector>
#include <math.h>   
using namespace std;

// Given base = B create a number line ;
// etc if B = 2; we have [0,1,10,11];
// etc if B = 5; we have [0,1,2,3,4,10,11,12,13,14]
vector<int> base_number_line(string B) {
    vector<int> arr;
    int b = stoi(B);
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
    // for (int x = 0;x<arr.size();x++) {
    //     cout << arr[x] << endl;
    // }
    // cout<< endl;
    return arr;
}


// Given string I, which is basically an integer
// Return a vector containing the digits of the integer
vector<int> string_to_vector_reversed(string I) {
    vector<int> integer;
    int i = 0;
    for (int j = I.size(); j > 0; j--) {
        i = (int)I[j - 1];
        integer.push_back(i - 48);
    }

    // cout << "Number of digits is " << I.size() << endl;
    // for (int j= 0; j < integer.size();j++) {
    //     cout << integer[j] << endl;
    // }
    // cout << endl;
    return integer;
}


vector<int> school_addition(vector<int> i1, vector<int> i2, vector<int> base_line) {

    int j = 0;
    int s = 0;
    int c = 0;

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
            // cout << i1[j] << " " << i2[j] << " " << endl;        
            s = base_line[i1[j] + i2[j] + c];
            // cout << "s = " << s << endl;
            // cout << "durp1" <<endl;
            if (s >= 10) {
                // cout << "adding to vector" << endl;
                result.push_back(s % 10);
                // cout << "added to vector" << endl;
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
            // cout << "final carry over; s = " << s << endl;
            result.push_back(s);
            break;

        }

    }

    // cout << "Addition" <<endl;               
    // cout << "i1 i2 s" <<endl;
    // for (int j=0; j < result.size();j++) 
    // {   
    //     if ((to_string(i1[j]).size()>1) && (to_string(i2[j]).size()>1)) {
    //         cout << " " << "0" << "  " << "0" <<" "<<  result[j] << endl;
    //     } else {
    //         cout << " " <<i1[j] << "  " << i2[j] <<" "<<  result[j] << endl;
    //     }
    // }


    // cout <<endl;

    return result;
}



vector<int> school_subtraction(vector<int> i1, vector<int> i2, int base) {
    // Implement school subtraction for karatsuba, i1 should always be the greater number;
    int j = 0;
    int c = 0;

    vector<int> result;
    int max_size = i1.size();
    int min_size = i2.size();

    // Ensure both vectors are of same size 
    if (max_size > min_size) {
        for (int i = 0; i < max_size - min_size; i++) {
            i2.push_back(0);
        }
    }

    while (j < max_size || c >= 1) {
        // cout << "s = " << s << endl;
        // cout << "durp1" <<endl;
        if (i1[j] - c < i2[j]) {
            // cout << "adding to vector" << endl;
            result.push_back(i1[j] + base - i2[j] - c);
            // cout << "added to vector" << endl;
            c = 1;
        }
        else {
            result.push_back(i1[j] - i2[j] - c);
            c = 0;
        }
        j++;
    }
    // cout << "Subtraction" <<endl;               
    // cout << "i1 i2 s" <<endl;
    // for (int j=0; j < result.size();j++) 
    // {   
    //     cout << " " <<i1[j] << "  " << i2[j] <<" "<<  result[j] << endl;
    // }

    // cout <<endl;
    return result;
}



// vector to string
// vector to string
string vector_to_string(vector<int> vec)
{
    string s = "";
    for (int j = vec.size() - 1; j >= 0; j--)
    {
        s = s + to_string(vec[j]);
    }

    string result = s;
    string c;
    int size = vec.size();
    int x;
    for (int j = 0; j < size - 1; j++) {
        c = s.at(j);
        x = stoi(c);
        // cout << x << endl ;
        if (x == 0) {
            // cout << "durp" << endl;
            result.erase(0, 1);
        }
        else {
            break;
        }
    }

    return result;
}


int digit_multiply(int x, int y, int b) {
    int result = 0;
    vector<int> base_line = base_number_line(to_string(b));
    result = base_line[x * y];
    return result;
}


// //  use only for n < 3; 
vector<int> school_multiplication(vector<int> i1, vector<int> i2, int b)
{

    vector<int> temp, result, carry1, carry2;
    string str;

    int max_size = max(i1.size(), i2.size());
    int min_size = min(i1.size(), i2.size());
    int c = 0;
    int j = 0;
    int s = 0;
    int k = 0;
    vector<int> base_line = base_number_line(to_string(b));

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


    while (j < max_size) {
        carry1.push_back(0);
        carry2.push_back(0);

        temp.clear();
        for (int x = 0; x < j; x++) {
            temp.push_back(0);
        }

        k = 0;
        while (k < max_size) {
            carry1.push_back(0);
            carry2.push_back(0);

            // cout << endl;
            s = digit_multiply(i2[j], i1[k], b);
            temp.push_back(s % 10);
            // cout << "Multiplied " << i2[j] << " and " << i1[k] << " to get "<< s << "; added " << s%10 << " to vector" << endl;

            if (j == 0) {
                // cout << "adding to carry1; current = "<< carry1[k+j+1]<< "; ++" << s/10 << " = " <<  carry1[k+j+1] + s/10 << endl;
                carry1[k + j + 1] = carry1[k + j + 1] + s / 10;
            }
            else if (j == 1) {
                // cout << "adding to carry2; current = "<< carry2[k+j+1]<< "; ++" << s/10 << " = " <<  carry2[k+j+1] + s/10 << endl;
                carry2[k + j + 1] = carry2[k + j + 1] + s / 10;
            }

            k++;
        }

        result = school_addition(result, temp, base_number_line(to_string(b)));
        j++;
    }


    // cout << "carry1" <<endl;               
    // for (int j=0; j < carry1.size();j++) 
    // {   
    //     cout << carry1[j] << endl;
    // }
    // cout << endl;

    // cout << "carry2" <<endl;               
    // for (int j=0; j < carry2.size();j++) 
    // {   
    //     cout << carry2[j] << endl;
    // }
    // cout << endl;

    result = school_addition(result, carry1, base_number_line(to_string(b)));
    result = school_addition(result, carry2, base_number_line(to_string(b)));

    result = string_to_vector_reversed(vector_to_string(result));

    // cout << "Multiplication" <<endl;               
    // cout << "i1 i2 s" <<endl;
    // for (int j=0; j < result.size();j++) 
    // {   
    //     cout << " " <<i1[j] << "  " << i2[j] <<" "<<  result[j] << endl;
    // }
    // cout << endl;

    return result;
}





// / karastuba multiplication
vector<int> karatsuba(vector<int> i1, vector<int> i2, vector<int> base_line)
{
    // cout << endl;
    int b = base_line[base_line.size() - 1] % 10 + 1;
    // base case: when both integers are 1 digit each
    if (max(i1.size(), i2.size()) < 3)
    {
        return school_multiplication(i1, i2, b);
    }

    /* calculates the size of the numbers(number of digits in the numbers) */
    else {
        int m = max(i1.size(), i2.size()) / 2;
        // cout << "10s = " << m << endl;

        vector<int> low1, low2;
        int min1 = min(i1.size(), max(i1.size(), i2.size()) / 2);
        int min2 = min(i2.size(), max(i1.size(), i2.size()) / 2);
        for (int i = 0; i < min1; i++) {
            low1.push_back(i1[i]);
        }
        for (int i = 0; i < min2; i++) {
            low2.push_back(i2[i]);
        }


        vector<int> high1, high2;
        int max1 = max(i1.size(), max(i1.size(), i2.size()) / 2);
        int max2 = max(i2.size(), max(i1.size(), i2.size()) / 2);
        for (int i = m; i < max1; i++) {
            high1.push_back(i1[i]);
        }
        for (int i = m; i < max2; i++) {
            high2.push_back(i2[i]);
        }

        // Make sure that if empty, then should be at least 0
        if (low1.size() == 0) {
            low1.push_back(0);
        }
        if (low2.size() == 0) {
            low2.push_back(0);
        }
        if (high1.size() == 0) {
            high1.push_back(0);
        }
        if (high2.size() == 0) {
            high2.push_back(0);
        }


        // cout << "Low1 = "<< vector_to_string(low1) << "; High1 = " << vector_to_string(high1)<< endl;
        // cout << "Low2 = "<< vector_to_string(low2) << "; High2 = " << vector_to_string(high2)<< endl;


        // Begin karatsuba multiplication

        vector<int> z0 = karatsuba(low1, low2, base_line); //z0=low1*low2
        // cout << "Calculate z0, multiply "<< vector_to_string(low1) << " & " << vector_to_string(low2) << " to get z0 = " << vector_to_string(z0) <<endl;

        vector<int> z2 = karatsuba(high1, high2, base_line); // z2= high1*high2
        // cout << "Calculate z2, multiply "<< vector_to_string(high1) << " & " << vector_to_string(high2) << " to get z2 = " << vector_to_string(z2) <<endl;


        vector<int> sum1 = school_addition(low1, high1, base_line);
        vector<int> sum2 = school_addition(low2, high2, base_line);

        vector<int> z1 = karatsuba(sum1, sum2, base_line); //z1=(low1 + high1)*(low2 + high2)
        // cout << "Calculate z1, multiply "<< vector_to_string(sum1) << " & " << vector_to_string(sum2) << " to get z1 = " << vector_to_string(z1) <<endl;

        // cout << "z0 z1 z2" << endl;               
        // for (int j=0; j < max(z0.size(),z1.size());j++) 
        // {   
        //     cout << " " << z0[j] << "  " << z1[j] <<" "<< z2[j] << endl;
        // }
        // cout << endl;


        vector<int> z2_b1k = z2;
        vector<int> z2_b2k = z2;

        vector<int> z0_b1k = z0;
        vector<int> z1_b1k = z1;

        for (int i = 0; i < m; i++) {
            z0_b1k.insert(z0_b1k.begin(), 0);
            z1_b1k.insert(z1_b1k.begin(), 0);
            z2_b1k.insert(z2_b1k.begin(), 0);

            z2_b2k.insert(z2_b2k.begin(), 0);
            z2_b2k.insert(z2_b2k.begin(), 0);
        }

        vector<int> result = school_addition(z1_b1k, z2_b2k, base_line);
        result = school_addition(result, z0, base_line);
        result = school_subtraction(result, z2_b1k, b);
        result = school_subtraction(result, z0_b1k, b);


        // cout << "Karatsuba" << endl;               
        // cout << "i1 i2 s" << endl;
        // for (int j=0; j < result.size()-1;j++) 
        // {   
        //     cout << " " << i1[j] << "  " << i2[j] <<" "<<  result[j] << endl;
        // }
        // cout << endl;


        return result;

    }

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


    // cout << "I1 = " << I1 << "; I2 = " << I2 << "; B = " << B << endl;

    // // <
    // // Get number line given base = B
    // vector<int> arr1 = base_number_line("2");
    // vector<int> arr2 = base_number_line("3");
    // vector<int> arr3 = base_number_line("4");
    // vector<int> arr4 = base_number_line("5");
    // vector<int> arr5 = base_number_line("6");
    // vector<int> arr6 = base_number_line("7");
    // vector<int> arr7 = base_number_line("8");
    // vector<int> arr8 = base_number_line("9");



    //  TEst cases for school_addition
    // vector<int> sum1 = school_addition(string_to_vector_reversed("3"),string_to_vector_reversed("4"),base_number_line("9"));
    // vector<int> sum2 = school_addition(string_to_vector_reversed("0"),string_to_vector_reversed("4"),base_number_line("9"));
    // vector<int> sum3 = school_addition(string_to_vector_reversed("3453431"),string_to_vector_reversed("352148"),base_number_line("9"));
    // vector<int> sum4 = school_addition(string_to_vector_reversed("14"),string_to_vector_reversed("0"),base_number_line("9"));
    // vector<int> sum5 = school_addition(string_to_vector_reversed("18"),string_to_vector_reversed("1"),base_number_line("9"));
    // vector<int> sum6 = school_addition(string_to_vector_reversed("2483767"),string_to_vector_reversed("1"),base_number_line("9"));
    // vector<int> sum8 = school_addition(string_to_vector_reversed("2483"),string_to_vector_reversed("0"),base_number_line("9"));
    // vector<int> sum9 = school_addition(string_to_vector_reversed("22"),string_to_vector_reversed("1"),base_number_line("3"));
    // vector<int> sum10 = school_addition(string_to_vector_reversed("101101011101010101010101011"),string_to_vector_reversed("101010101010101010101010101011011"),base_number_line("2"));
    // vector<int> sum11 = school_addition(string_to_vector_reversed("101101011101010101010101011"),string_to_vector_reversed("34"),base_number_line("5"));
    // vector<int> sum12 = school_addition(string_to_vector_reversed("124325524354353246123565314264364253141254325314325643345435434356432234324463354324231231234345453543543432234324234354256436543542323423453252"),string_to_vector_reversed("123424513242134123213123213423535443565434352342312345466546545465434232213231345564654654465645654546654654654654231312123213231213123213231231231213"),base_number_line("7"));
    // vector<int> sum13 = school_addition(string_to_vector_reversed("7546431745323421342753434512321343454564574563452341231234"),string_to_vector_reversed("0"),base_number_line("8"));

    // //  TEst cases for school_subtraction
    // vector<int> sum1 = school_subtraction(string_to_vector_reversed("4"),string_to_vector_reversed("3"),9);
    // vector<int> sum2 = school_subtraction(string_to_vector_reversed("4"),string_to_vector_reversed("0"),9);
    // vector<int> sum3 = school_subtraction(string_to_vector_reversed("3453431"),string_to_vector_reversed("352148"),9);
    // vector<int> sum4 = school_subtraction(string_to_vector_reversed("14"),string_to_vector_reversed("0"),9);
    // vector<int> sum5 = school_subtraction(string_to_vector_reversed("18"),string_to_vector_reversed("1"),9);
    // vector<int> sum6 = school_subtraction(string_to_vector_reversed("2483767"),string_to_vector_reversed("1"),9);
    // vector<int> sum8 = school_subtraction(string_to_vector_reversed("2483"),string_to_vector_reversed("0"),9);
    // vector<int> sum9 = school_subtraction(string_to_vector_reversed("100"),string_to_vector_reversed("1"),3);
    // vector<int> sum10 = school_subtraction(string_to_vector_reversed("101101011101010101010101011111111"),string_to_vector_reversed("101010101010101010101010101011011"),2);
    // vector<int> sum11 = school_subtraction(string_to_vector_reversed("101101011101010101010101011"),string_to_vector_reversed("34"),5);
    // vector<int> sum12 = school_subtraction(string_to_vector_reversed("124325524354353246123565314264364253141254325314325643345435434356432234324463354324231231234345453543543432234324234354256436543542323423453252"),string_to_vector_reversed("1234245132421354546654654654654231312123213231213123213231231231213"),7);
    // vector<int> sum13 = school_subtraction(string_to_vector_reversed("7546431745323421342753434512321343454564574563452341231234"),string_to_vector_reversed("0"),8);


    // //  TEst casses for digit multiply
    // digit_multiply(2,2,3);
    // digit_multiply(2,2,9);
    // digit_multiply(4,3,5);
    // digit_multiply(9,2,10);
    // digit_multiply(2,0,7);
    // digit_multiply(1,5,8);
    // digit_multiply(8,6,9);
    // digit_multiply(8,8,9);





    //  i1 = stoi(I1);/
    // int i2 = stoi(I2);
    // int b = stoi(B);

    // int
    // for (int j= 0; j < sum.size();j++) 
    // {
    //     cout << sum[j] << endl;
    // }

    // vector<int> sum1 = school_multiplication(string_to_vector_reversed("11"),string_to_vector_reversed("12"),3);
    // vector<int> sum2 = school_multiplication(string_to_vector_reversed("0"),string_to_vector_reversed("12"),3);
    // vector<int> sum3 = school_multiplication(string_to_vector_reversed("7"),string_to_vector_reversed("1"),8);
    // vector<int> sum4 = school_multiplication(string_to_vector_reversed("1"),string_to_vector_reversed("17"),8);
    // vector<int> sum5 = school_multiplication(string_to_vector_reversed("4"),string_to_vector_reversed("0"),6);
    // vector<int> sum6 = school_multiplication(string_to_vector_reversed("4"),string_to_vector_reversed("10"),10);

    // vector<int> sum7 = school_multiplication(string_to_vector_reversed("16"),string_to_vector_reversed("37"),9);
    // vector<int> sum8 = school_multiplication(string_to_vector_reversed("23"),string_to_vector_reversed("14"),5);
    // vector<int> sum9 = school_multiplication(string_to_vector_reversed("2"),string_to_vector_reversed("56"),7);

    // vector<int> sum10 = school_multiplication(string_to_vector_reversed("75"),string_to_vector_reversed("77"),9);
    // vector<int> sum11 = school_multiplication(string_to_vector_reversed("11"),string_to_vector_reversed("10"),2);

    vector<int> s = school_addition(string_to_vector_reversed(I1), string_to_vector_reversed(I2), base_number_line(B));
    vector<int> k = karatsuba(string_to_vector_reversed(I1), string_to_vector_reversed(I2), base_number_line(B));

    // cout << "Multiplying " << I1 << "and " << I2 << " to get " << vector_to_string(k) << endl;
    // // 1668754 1236773 9 
    // // 754 773 9
    // // 75 77 9
    string s_addition = vector_to_string(s);
    string k_final = vector_to_string(k);

    cout << s_addition << " " << k_final << endl;
    return 0;
}
