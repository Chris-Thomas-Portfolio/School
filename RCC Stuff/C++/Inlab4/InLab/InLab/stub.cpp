#include <iostream>
using namespace std;

class Shape
{
public:
    Shape()
    {
        cout << "Shape ctor\n";
    }
    Shape(const Shape& obj)
    {
        cout << "Shape copy ctor\n";
    }
    virtual ~Shape()
    {
        cout << "Shape dtor\n";
    }
    virtual void draw()
    {
        cout << "Shape\n";
    }
};

class Circle : public Shape
{
public:
    Circle()
    {
        cout << "Circle ctor\n";
    }
    Circle(const Circle& obj)
    {
        cout << "Circle copy ctor\n";
    }
    ~Circle()
    {
        cout << "Circle dtor\n";
    }
    void draw()
    {
        cout << "Circle\n";
    }
};

class Rect : public Shape
{
public:
    Rect()
    {
        cout << "Rect ctor\n";
    }
    Rect(const Rect& obj)
    {
        cout << "Rect copy ctor\n";
    }
    ~Rect()
    {
        cout << "Rect dtor\n";
    }
    void draw()
    {
        cout << "Rect\n";
    }
};

void fun1(Shape* obj);
void fun2(Shape obj);
void fun3(Shape* obj);
void fun4(Shape* obj);

void fun1(Shape* obj)
{
    obj->draw();
}

void fun2(Shape obj)
{
    obj.draw();
}

void fun3(Shape* obj)
{
    Circle* ptr = dynamic_cast<Circle*>(obj);
    if (ptr == nullptr)
        cout << "--- fun3 NOT successful ---" << endl;
    else
        cout << "--- fun3 successful ---" << endl;
}

void fun4(Shape* obj)
{
    try
    {
        Circle& ptr = dynamic_cast<Circle&>(*obj);
        cout << "--- fun4 successful ---" << endl;
    }
    catch (std::bad_cast)
    {
        cout << "--- fun4 NOT successful ---" << endl;
    }
}

int main()
{
    cout << "\n---A---\n\n";
    Shape* shapes[3];

    shapes[0] = new Shape;
    shapes[1] = new Circle;
    shapes[2] = new Rect;

    cout << "\n---B---\n\n";

    fun2(*(shapes[1]));

    cout << "\n---C---\n\n";

    fun3(shapes[0]);
    fun3(shapes[1]);

    cout << "\n---D---\n\n";

    fun4(shapes[0]);
    fun4(shapes[1]);

    cout << "\n---E---\n\n";

    for (int i = 0; i < 3; i++)
    {
        fun1(shapes[i]);
    }

    cout << "\n---F---\n\n";
    cout << typeid(shapes[0]).name() << endl;
    cout << typeid(shapes[1]).name() << endl;
    cout << typeid(*(shapes[2])).name() << endl;

    cout << "\n---G---\n\n";

    for (int i = 0; i < 3; i++)
    {
        delete shapes[i];
    }

    return 0;
}