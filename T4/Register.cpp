
#include "Register.h"
using namespace std;
Register::Register() {
reggister.resize(16);

}
void Register:: setcell(int address, const string& val){
if(address>=0 && address<16){
   reggister[address]=val;
}
};
string Register:: getcell(int address) const{
    return address>=0 && address<16?reggister[address]:"00";
};
