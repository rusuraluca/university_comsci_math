#include "Interface/FilteringCriteria.h"#include "Interface/FilteringCriteriaAnd.h"#include "Interface/FilteringCriteriaOr.h"#include "Interface/FilteringPrice.h"#include "Interface/FilteringType.h"#include "Interface/FilteringDeparture.h"#include "iostream"int main() {    DynamicArray<Offer> arr, filteredArr;    Offer o1('1', "Bucharest", "Ibiza", 400, Date(12,03,2022), Date(19,03,2022), circuit);    Offer o2('2', "California", "Malibu", 100, Date(14,03,2022), Date(29,04,2022), cruise);    Offer o3('3', "Bucharest", "Rome", 350, Date(12,03,2022), Date(19,03,2022), cityBreak);    Offer o4('4', "Malibu", "Bucharest", 250, Date(12,03,2022), Date(19,03,2022), cityBreak);    Offer o5('5', "Rome", "Bucharest", 350, Date(12,03,2022), Date(19,03,2022), cityBreak);    arr.append(o1);    arr.append(o2);    arr.append(o3);    arr.append(o4);    arr.append(o5);    FilteringCriteriaAnd* fcand = new FilteringCriteriaAnd();    FilteringCriteriaOr* fcor = new FilteringCriteriaOr();    FilteringCriteria* crt1 = new FilteringPrice(500);    FilteringCriteria* crt2 = new FilteringType(circuit);    FilteringCriteria* crt3 = new FilteringDeparture("Bucharest");    int i = 0;    cout << ++i;    fcand->setC1(crt1);    fcand->setC2(crt2);    filteredArr = fcand->filter(arr);    cout << filteredArr << endl;    cout << ++i;    fcand->setC2(crt3);    filteredArr = fcand->filter(arr);    cout << filteredArr << endl;    cout << ++i;    fcand->setC1(crt2);    filteredArr = fcand->filter(arr);    cout << filteredArr << endl;    cout << ++i;    fcor->setC1(crt1);    fcor->setC2(crt2);    filteredArr = fcor->filter(arr);    cout << filteredArr << endl;    cout << ++i;    fcor->setC2(crt3);    filteredArr = fcor->filter(arr);    cout << filteredArr << endl;    cout << ++i;    fcor->setC1(crt2);    filteredArr = fcor->filter(arr);    cout << filteredArr << endl;    return 0;}