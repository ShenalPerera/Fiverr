#ifndef CLOCK_CLOCK_H
#define CLOCK_CLOCK_H
class Clock{
    protected:
        int hours;
        int minutes;
        int seconds;

    public:
        Clock(int hours, int minutes, int seconds);

        // get methods
        int getHours();
        int getMinutes();
        int getSeconds();

        // set methods
        void setHours(int hours);
        void setMinutes(int minutes);
        void setSeconds(int seconds);

        // Method to display the clock with the current time
        void display();

        // Methods to add Hours , Minutes , and seconds to the current time
        void addHours();
//        virtual void addMinutes();
//        virtual void addSeconds();
};
#endif //CLOCK_CLOCK_H
