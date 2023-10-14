/**
 * @file modules.h
 * @author Jesutofunmmi Kupoluyi (jimsufficiency@gmail.com)
 * @brief This is a header file containing the class definitions
 * for the hardware modules used.
 * @version 0.1
 * @date 2023-09-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

class led
{
private:
    /* data */
public:
 led(uint8_t pin, uint8_t port);
    ~led();
};
 led::led(uint8_t pin, uint8_t* port)
{
    
}
 led::~led()
{
}
