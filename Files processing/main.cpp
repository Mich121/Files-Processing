#include "BinaryFile.h"
#include "CsvFile.h"
#include "FileFactory.h"

int main()
{
    /*
    //writing elements from file to vector
    BinaryFile bf1("test.bin", "r");
    std::vector<Point> v1;
    bf1.Read(v1);
    for (Point& element : v1)
    {
        std::cout << element.x << " " << element.y << " " << element.z << "\n";
    }
    */
    /*
    //writing elements from file to vector
    CsvFile csf1("test.csv", "r");
    std::vector<Point> v2;
    csf1.Read(v2);
    for (Point& element : v2)
    {
        std::cout << element.x << " " << element.y << " " << element.z << "\n";
    }
    */
    /*
    //writing generated vector to file
    CsvFile csf2("enter.csv", "w");
    std::vector<Point> v3;
    Point point;
    for (int i = 0; i < 1000; i++)
    {
        double number1 = rand();
        double number2 = rand();
        double number3 = rand();
        point.x = number1;
        point.y = number2;
        point.z = number3;
        v3.push_back(point);
    }
    for (auto& x : v3)
        std::cout << x.x << " " << x.y << " " << x.z << "\n";
    csf2.Write(v3);
    */
    /*
    //writing elements from file to point
    CsvFile csf3("test.csv", "r");
    Point p1;
    csf3.Read(p1, 45);
    std::cout << p1.x << " " << p1.y << " " << p1.z << "\n";
    */

    ////////////////////////////////////////////////////////////////////////////////
    //testing 'FileFactory' which is one of creational design pattern named factory
    /*
    //get some line and give to point
    Point pp;
    IFile* i1;
    i1 = FileFactory::Open("test.csv", "r");
    i1->Read(pp, 961);
    std::cout << pp.x << " " << pp.y << " " << pp.z << "\n";

    i1 = FileFactory::Open("test.bin", "r");
    i1->Read(pp, 961);
    std::cout << pp.x << " " << pp.y << " " << pp.z << "\n";
    */
    /*
    //writing generated vector to file
    IFile* i2;
    i2 = FileFactory::Open("enter.csv", "w");
    std::vector<Point> v4;
    Point point;
    for (int i = 0; i < 1000; i++)
    {
        double number1 = rand();
        double number2 = rand();
        double number3 = rand();
        point.x = number1;
        point.y = number2;
        point.z = number3;
        v4.push_back(point);
    }
    for (auto& x : v4)
        std::cout << x.x << " " << x.y << " " << x.z << "\n";
    i2->Write(v4);
    */
    /*
    //writing elements from file to point
    IFile* i3;
    i3 = FileFactory::Open("test.csv", "r");
    Point p1;
    i3->Read(p1, 125);
    std::cout << p1.x << " " << p1.y << " " << p1.z << "\n";

    IFile* i4;
    i4 = FileFactory::Open("test.bin", "r");
    Point p2;
    i4->Read(p2, 125);
    std::cout << p2.x << " " << p2.y << " " << p2.z << "\n";
    */
}

