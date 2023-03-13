//
// Created by loisb on 06.04.2022.
//

#include "Bill.h"

std::string Bill::ToString() {
        std::stringstream bill;
        bill << this->name << " ; " << this->day << " ; " << this->month << " ; " << this->year<< " ; "<<this->sum<<" ; "<<this->isPaid;
        return bill.str();


}
