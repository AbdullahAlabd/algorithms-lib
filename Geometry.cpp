
struct point{
    long long x, y, z;
};

point crossProduct(point u, point v){
    /*
        |   i       j       k     |
        |   u.x     u.y     u.z   |
        |   v.x     v.y     v.z   |
    */
    point w;
    w.x = u.y*v.z - u.z*v.y;
    w.y = u.z*v.x - u.x*v.z;
    w.z = u.x*v.y - u.y*v.x;
    return w;
}

bool onLine(point a, point b, point c){
    point v = {b.x-a.x, b.y-a.y, b.z-a.z}, u ={c.x-a.x, c.y-a.y, c.z-a.z}; // v from a to b, u from a to c;
    point w = crossProduct(v, u);
    return (w.x == 0 && w.y == 0 && w.z == 0); // isEqual to the zero vector
}
