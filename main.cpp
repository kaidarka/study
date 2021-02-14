#include <iostream>
#include <vector>
#include <math.h>
 
using namespace std;

// Подсчет погрешностей суммы 
void Sum(const vector<double> &num, const vector<double> &errAbs)
{
  double sumNum = 0, 
         sumErrAbs = 0, 
         sumErrRelative = 0;
  for (const auto &count : num)
    sumNum += count;
  for (const auto &count : errAbs)
    sumErrAbs += count;
  sumErrRelative = abs(sumErrAbs / sumNum);
  cout << "1)" << endl
       << "Сумма чисел: " << sumNum << endl
       << "Абсолютная погрешность: " << sumErrAbs << endl
       << "Относительная погрешность: " << sumErrRelative << endl
       << endl;
}

// Подсчет погрешностей произведения
void Mult(const vector<double> &num, const vector<double> &errAbs)
{
  double multNum = 1, multErrAbs = 0, multErrRel = 0;
  for (const auto &count : num)
    multNum *= count;
  for (int i = 0; i < num.size(); i++)
    multErrRel += errAbs[i] / num[i];
  multErrAbs = multErrRel * multNum;
  cout << "2)" << endl
       << "Произведение: " << multNum << endl
       << "Абсолютная погрешность: " << multErrAbs << endl
       << "Относительная погрешность: " << multErrRel << endl
       << endl;
}

int main()
{
// Числа
  vector<double> num = {15.12234, 1.9, 3.14};     
// Их абсолютные погрешности 
  vector<double> errAbs = {0.000005, 0.05, 0.005}; 
// Подсчет
  Sum(num, errAbs);                          
  Mult(num, errAbs);                         
  return 0;
}
 

