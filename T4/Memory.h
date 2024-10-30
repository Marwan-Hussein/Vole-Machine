

#ifndef MEMORY_H
#define MEMORY_H
class Memory {
    vector<string> memory;
public:
    Memory() ;
    void setcell(int address, const string& val);
    string getcell(int address) const;
    ~Memory()=default;
};
#endif //MEMORY_H
