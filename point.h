class point
{
private:
    /* data */
    int pos_x, pos_y, velocity, tail;
public:
    point(int, int, int, int);
    point(){};
    ~point();
    void setX(int);
    void setY(int);
    void setV(int);
};