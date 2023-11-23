#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <cctype>
#include "String"

using namespace std;

#define AVANT 0
#define APRES 1
#define AVANT_APRES 2
#define SQRT 'v'
#define LOG 'o'
#define LN 'n'

int max(const vector<uint16_t> &tableau);
void multiplication_implicite(const uint8_t &position, vector<char> &operator_list, vector<uint16_t> &priorite_list, string &calc_input, uint16_t &priorite, uint16_t i);
double calc(string &calc_input, double &ans);
double sous_calc(string &calc_input, double &ans, uint16_t &i);

int max(const vector<uint16_t> &tableau)
{
    int max = tableau[0];

    for (size_t i = 1; i < tableau.size(); i++)
    {
        if (tableau[i] > max)
        {
            max = tableau[i];
        }
    }

    return max;
}

bool is_num(string &calc_input, uint16_t i)
{
    if (isdigit(calc_input[i]))
        return true;
    if (calc_input[i] == 'e')
        return true;
    if (calc_input.substr(i - 1, 2) == "pi")
        return true;
    return false;
}

void multiplication_implicite(const uint8_t &position, vector<char> &operator_list, vector<uint16_t> &priorite_list, string &calc_input, uint16_t &priorite, uint16_t i)
{
    if (position == 0 or position == 2)
    {
        if (i - 1 >= 0)
            if (is_num(calc_input, i - 1))
            {
                operator_list.push_back('*');
                priorite_list.push_back(priorite + 1);
            }
    }
    if (position == 1 or position == 2)
    {
        do
        {
            if (i + 1 < calc_input.length())
            {
                if (is_num(calc_input, i + 1))
                {
                    operator_list.push_back('*');
                    priorite_list.push_back(priorite + 1);
                    break;
                }
                else if (calc_input[i + 1] == '(')
                    i++;
                else break;
            }
            else
                break;
        } while (true);
    }
}

double calc(string &calc_input, double &ans)
{
    vector<char> operator_list;
    vector<double> num_list;
    vector<uint16_t> priorite_list;
    uint16_t calc_input_len = calc_input.length();
    bool is_negatif = false;

    uint16_t pos = 0;
    uint16_t priorite = 0;

    for (uint16_t i = 0; i < calc_input_len; i++)
    {
        pos = i;
        if (calc_input[i] >= '0' && calc_input[i] <= '9')
        {

            while (calc_input[i] >= '0' && calc_input[i] <= '9')
                i++;
            if (!is_negatif)
                num_list.push_back(stof(calc_input.substr(pos, i - pos)));
            else
            {
                num_list.push_back(-stof(calc_input.substr(pos, i - pos)));
                is_negatif = false;
            }
            if (i >= calc_input_len)
                break;
        }

        switch (calc_input[i])
        {
        case '(':
            multiplication_implicite(AVANT, operator_list, priorite_list, calc_input, priorite, i);
            priorite += 3;
            break;
        case ')':
            priorite -= 3;
            multiplication_implicite(APRES, operator_list, priorite_list, calc_input, priorite, i);
            if (priorite < 0)
                throw runtime_error("Il y a un probleme de parenthese !");
            break;
        case '^':
            priorite_list.push_back(priorite + 2);
            operator_list.push_back(calc_input[i]);
            break;
        case '*':
        case '/':
            priorite_list.push_back(priorite + 1);
            operator_list.push_back(calc_input[i]);
            break;
        case '-':
            if (i == 0)
                is_negatif = true;
            else if (calc_input[i - 1] == '(')
                is_negatif = true;
            else
            {
                priorite_list.push_back(priorite);
                operator_list.push_back(calc_input[i]);
            }
            break;
        case '+':
            priorite_list.push_back(priorite);
            operator_list.push_back(calc_input[i]);
            break;
        case 'e':
            num_list.push_back(exp(1.0));
            multiplication_implicite(AVANT, operator_list, priorite_list, calc_input, priorite, i);
            if (i + 2 < calc_input_len)
            {
                if (calc_input.substr(i, 3) == "exp")
                {
                    operator_list.push_back('^');
                    priorite_list.push_back(priorite + 2);
                    i += 2;
                    break;
                }
            }
            multiplication_implicite(APRES, operator_list, priorite_list, calc_input, priorite, i);
            break;
        case 'p':
            multiplication_implicite(AVANT, operator_list, priorite_list, calc_input, priorite, i);
            if (i + 1 < calc_input_len)
            {
                if (calc_input.substr(i, 2) == "pi")
                {
                    num_list.push_back(M_PI);
                    i += 1;
                }
                else
                    throw runtime_error("Valeur entrée est incorrect !");
            }
            else
                throw runtime_error("Valeur entrée est incorrect !");
            multiplication_implicite(APRES, operator_list, priorite_list, calc_input, priorite, i);
            break;
        case 's':
            if (i + 2 < calc_input_len)
            {
                multiplication_implicite(AVANT, operator_list, priorite_list, calc_input, priorite, i);
                if (calc_input.substr(i, 3) == "sin")
                {
                    i += 2;
                    num_list.push_back(sin(sous_calc(calc_input, ans, i)));
                    if (calc_input[i] == ')')
                        multiplication_implicite(APRES, operator_list, priorite_list, calc_input, priorite, i);
                    break;
                } else if (i + 3 < calc_input_len)
                {
                    if (calc_input.substr(i, 4) == "sqrt")
                    {
                        num_list.push_back(2);
                        operator_list.push_back(SQRT);
                        priorite_list.push_back(priorite + 2);
                        i += 3;
                        break;
                    }
                }
            }
            throw runtime_error("Valeur entrée est incorrect !");
            break;
        case 'l':
            if (i + 2 < calc_input_len)
            {
                multiplication_implicite(AVANT, operator_list, priorite_list, calc_input, priorite, i);
                if (calc_input.substr(i, 2) == "ln")
                {
                    i += 1;
                    num_list.push_back(log(sous_calc(calc_input, ans, i)));
                    if (calc_input[i] == ')')
                        multiplication_implicite(APRES, operator_list, priorite_list, calc_input, priorite, i);
                    break;
                }
                else if (i + 3 < calc_input_len)
                {
                    if (calc_input.substr(i, 3) == "log")
                    {
                        i += 2;
                        num_list.push_back(log10(sous_calc(calc_input, ans, i)));
                        if (calc_input[i] == ')')
                            multiplication_implicite(APRES, operator_list, priorite_list, calc_input, priorite, i);
                        break;
                    }
                }
            }
            throw runtime_error("Valeur entrée est incorrect !");
            break;
        case 'c':
            if (i + 2 < calc_input_len)
            {
                multiplication_implicite(AVANT, operator_list, priorite_list, calc_input, priorite, i);
                if (calc_input.substr(i, 3) == "cos")
                {
                    i += 2;
                    num_list.push_back(cos(sous_calc(calc_input, ans, i)));
                    if (calc_input[i] == ')')
                        multiplication_implicite(APRES, operator_list, priorite_list, calc_input, priorite, i);
                    break;
                }
            }
            throw runtime_error("Valeur entrée est incorrect !");
            break;
        case 't':
            if (i + 2 < calc_input_len)
            {
                multiplication_implicite(AVANT, operator_list, priorite_list, calc_input, priorite, i);
                if (calc_input.substr(i, 3) == "tan")
                {
                    i += 2;
                    num_list.push_back(tan(sous_calc(calc_input, ans, i)));
                    if (calc_input[i] == ')')
                        multiplication_implicite(APRES, operator_list, priorite_list, calc_input, priorite, i);
                    break;
                }
            }
            throw runtime_error("Valeur entrée est incorrect !");
            break;
        case 'a':
            if (i + 2 < calc_input_len)
                if (calc_input.substr(i, 3) == "ans")
                {
                    num_list.push_back(ans);
                    multiplication_implicite(AVANT_APRES, operator_list, priorite_list, calc_input, priorite, i);
                    i += 2;
                    break;
                }
            throw runtime_error("Valeur entrée est incorrect !");
            break;
        default:
            throw runtime_error("Valeur entrée est incorrect !");
            break;
        }
    }

    /// DEBUT DEBUG
    /*for (int i = 0; i < num_list.size(); i++)
        cout << num_list[i] << ", ";
    cout << endl;

    for (int i = 0; i < operator_list.size(); i++)
        cout << operator_list[i] << ", ";
    cout << endl;

    for (int i = 0; i < priorite_list.size(); i++)
        cout << priorite_list[i] << ", ";
    cout << endl;*/
    /// FIN DEBUG

    if (num_list.size() != (operator_list.size() + 1))
        throw runtime_error("Le calcule est impossible !");
    ;

    if (priorite_list.size() > 0 and operator_list.size() > 0)
    {
        int max_priorite = max(priorite_list);
        while (true)
        {
            for (int i = 0; i < operator_list.size(); i++)
            {
                if (max_priorite == priorite_list[i])
                {
                    switch (operator_list[i])
                    {
                    case '+':
                        num_list[i + 1] += num_list[i];
                        break;
                    case '-':
                        num_list[i + 1] = num_list[i] - num_list[i + 1];
                        break;
                    case '*':
                        num_list[i + 1] = num_list[i] * num_list[i + 1];
                        break;
                    case '/':
                        if (num_list[i + 1] == 0)
                            throw runtime_error("Division par zero impossible !");
                        ;
                        num_list[i + 1] = num_list[i] / num_list[i + 1];
                        break;
                    case '^':
                        num_list[i + 1] = pow(num_list[i], num_list[i + 1]);
                        break;
                    case SQRT:
                        num_list[i + 1] = pow(num_list[i + 1], 1 / num_list[i]);
                        break;
                    }
                }
            }
            int size_priorite_list = operator_list.size() - 1;
            if (max_priorite != 0)
            {
                for (int i = size_priorite_list; i >= 0; i--)
                {
                    if (max_priorite == priorite_list[i])
                    {
                        num_list.erase(num_list.begin() + i);
                        operator_list.erase(operator_list.begin() + i);
                        priorite_list.erase(priorite_list.begin() + i);
                    }
                }
                max_priorite--;
            }
            else
            {
                break;
            }
        }
    }
    return num_list[num_list.size() - 1];
}

double sous_calc(string &calc_input, double &ans, uint16_t &i)
{
    i++;
    uint16_t init_i = i;
    uint16_t unclose_parenthese = 0;
    if (calc_input[i] != '(')
    {
        bool is_number = false;
        do
        {
            if (i != (calc_input.length()))
            {
                if (is_num(calc_input, i))
                    i++;
                else
                    break;
            }
            else
                break;
        } while (1);
        string result = calc_input.substr(init_i, i - init_i);
        i--;
        return calc(result, ans);
    }
    else
    {
        do
        {
            if (i == (calc_input.length()))
                unclose_parenthese = 0;
            else if (calc_input[i] == '(')
                unclose_parenthese++;
            else if (calc_input[i] == ')')
                unclose_parenthese--;
            i++;
        } while (unclose_parenthese > 0);
        i--;
        init_i++;
        string result = calc_input.substr(init_i, i - init_i);
        return calc(result, ans);
    }
}

int main()
{
    double result = 0;
    while (true)
    {
        string calc_input = "";
        cin >> calc_input;
        try
        {
            result = calc(calc_input, result);
            cout << result << endl;
        }
        catch (const exception &e)
        {
            cerr << "Erreur :" << e.what() << '\n';
        }
    }
}