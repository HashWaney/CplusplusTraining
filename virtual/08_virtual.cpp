//
// Created by hash on 2020/6/22.
//
#include "iostream"

using namespace std;

//1。 虚函数与运行时多态
// 虚函数的调用取决于指向或者引用的对象的类型
// 《《《对象的类型》》》
// 而不是指针或者引用自身的类型
// 解读：比如一个Base指针 但是指向的是派生类，那么虚函数调用的是派生类的虚函数的实现
class School {
public:
    virtual void room() {
        cout << ">>>>School has many classroom<<<<" << endl;
    }
};

class Class : public School {
    virtual void room() {
        cout << ">>>>>Class combine from many class<<<<" << endl;
    }

};


// 2。虚函数中的默认参数
// 规则：虚函数是动态绑定，默认参数是静态绑定的，默认参数的使用要看指针或者应用本身的类型，而不是对象的类型
// 言外之意：定义的参数会使用左边定义的即声明的指针或者引用的类型的默认参数。

class Base {
public:
    virtual void fun(int x = 10) {
        cout << ">>>>>Base::fun(),x =" << x << endl;
    }
};

class Sample : public Base {
public:
    virtual void fun(int x = 20) {
        cout << ">>>>Sample::fun(), x=" << x << endl;
    }
};

// 3.1  静态函数可以声明为虚函数吗？（不能）
//      1。静态函数不能声明虚函数，同时也不能被const和volatile关键字修饰
//          static成员函数不属于任何类对象或类的实例，所以即使给此函数加上virtual没有任何意义
//       2。虚函数依靠的是vptr和vtable来处理，vptr是一个指针，在类的构造函数中创建生成，并且只能使用this
//           来访问它，静态成语函数没有this指针，所以无法访问vptr。静态函数无法被声明为虚函数，因为没有this指针，因此无法通过this指针
//           指向虚函数指针vptr。
//virtual static void fun(); //error
//static void fun2() const; //error
//static void fun3() volatile; // error

//3.2   构造函数可以为虚函数？（不能）
//      构造函数不可以声明为虚函数，同时除了inline｜explicit之外，构造函数不允许使用其他任何关键字
//      🀄️💊（重要）；尽管虚函数表vtable是在编译阶段就已经建立，但是指向虚函数表的指针vptr是在运行阶段实例化对象才会产生的。
//      其实这里的意思就是vptr是在构造（运行时阶段实例化对象的时候创建的，而虚函数表是在编译时期（就是你在编写了虚函数的）时候创建的——
//      那么编译时期早于运行时期， vptr还没创建出来，如果这个时候硬是要把构造弄成虚函数，那么意味着构造函数会被添加到虚函数表中
//      如果需要使用虚函数，需要vptr指向这个虚函数表的，那么这个时候构造被指定为了虚函数，意味着vptr无法使用，没法生成啊，因为是这样的啊，构造是virtual修饰的你怎么去找啊
//      必须通过vptr去指向这个虚函数表的，vptr都还没生成，怎么找啊？所以不能将构造声明为虚函数。


// 使用虚函数是因为需要在信息不全的情况下进行多态运行，而构造函数用来初始化实例，实例的类型必须是确定的；

class BaseFunction { // 抽象类
public:
    BaseFunction() {

    }

    BaseFunction(int id) {

    }

    virtual ~BaseFunction() {// 虚析构函数用来确保实例派生调用析构函数

    }

    static BaseFunction *Create(int id); // 创建一个派生类实例


    virtual void changeFunction() = 0; // 派生类的具体实现，

    virtual BaseFunction *clone() = 0; // 用来拷贝一份派生类的实例
};

class NormalFunction : public BaseFunction {
public:
    NormalFunction() {
        cout << ">>>>> Normal Function Construct <<<<<" << endl;

    }

    ~NormalFunction() {
        cout << ">>>> Normal Function Destruct  <<<<<" << endl;
    }

    NormalFunction(const NormalFunction &normalFunction) {

        cout << ">>>> NormalFunction impl clone to instantiation <<<<" << endl;
    }


    void changeFunction() override {
        cout << ">>>>> NormalFunction change Function <<<" << endl;
    }

    BaseFunction *clone() override {
        return new NormalFunction(*this);
    }

};

class SampleFunction : public BaseFunction {
public:
    SampleFunction() {
        cout << ">>>>>Sample Function Construct<<<<" << endl;
    }

    ~SampleFunction() {
        cout << ">>>>Sample Function Destruct<<<<<<" << endl;
    }

    SampleFunction(SampleFunction &sampleFunction) {
        cout << ">>>>>Sample Function impl clone to instantiation " << endl;
    }

    void changeFunction() override {
        cout << ">>>>Sample Function changeFunction<<<<<" << endl;
    }

    BaseFunction *clone() override {
        return new SampleFunction(*this);
    }
};

BaseFunction *BaseFunction::Create(int id) {
    if (id == 1) {
        return new SampleFunction;
    } else {
        return new NormalFunction;
    }
}

class User {

private:
    BaseFunction *p;
    int x;

public:
    User(int x) : p() {
        this->x = x;
        cout << ">>>>>User normal id -><<<<<< " << x << endl;
        p = BaseFunction::Create(x);
    }

    User() {

    }

    void setId(int x) {
        cout << ">>>>> User setId is x=<<<<<<" << x << endl;
        this->x = x;
        p = BaseFunction::Create(x);
    }

    ~User() {
        if (p) {
            delete p;
            p = 0;
        }
    }

    void action() {
        BaseFunction *baseFunction = p->clone(); // NormalFunction 的实例
        baseFunction->changeFunction(); // 调用NormalFunction的changeFunction方法
        delete baseFunction; // 创建的实例给销毁
    }
};



// 4.析构函数可以是虚函数吗？（可以）
// 析构函数可以声明为虚函数，如果需要删除一个指向派生类的基类指针时候，
// 应该把析构函数声明为虚函数，actual，只要一个类有可能被其他类所继承，就应该声明为析构函数、


//5.虚函数可以为私有函数吗？（可以， but)
// 基类指针指向继承对象，则调用继承类对象的函数
// int main()必须声明为基类的友元，否则编译失败，

class PrivateClassImpl;

class PrivateBaseClass {
private:
    virtual void fun() {
        cout << ">>>>>>PrivateBaseClass fun<<<<<<<<" << endl;
    }

    friend int main();


    // 将私有域改为公有的
public:
    virtual void publicFun() {
        cout << ">>>>>>>>>>>>PrivateBaseClass publicFunc<<<<<<<<<<<<" << endl;
    }

};

class PrivateClassImpl : public PrivateBaseClass {
public:
    void fun() {
        cout << ">>>>>>PrivateClassImpl fun<<<<<<<" << endl;
    }

private:
    void publicFun() {
        cout << ">>>>>>>>>>>>>>>>>PrivateClassImpl extends PrivateBaseClass publicFunc<<<<<<<<<<<<<<<<" << endl;
    }
};




//6. 虚函数可以被内联吗？
// 类成员函数都是被编译器考虑是否进行内联，但是通过基类指针或者引用调用的虚函数不能被内联，
// 实体对象调用虚函数或者静态调用时刻意被内联，虚析构函数的静态调用，也一定会被内联展开。

// -  虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现出多态性时候不能进行内联。
// -  内联是在编译时期建议编译器内联的，而虚函数的多态性在运行时，编译器无法知道运行时期调用哪个代码
//    因此虚函数表现为多态性时候（运行时期）不可以内联
// -  inline virtual唯一可以内联的时候：编译器知道所调用的对象是哪个类，这只有在编译器具有实际对象而不是对象的指针或者引才会发生。
class InlineBaseClass {
public:
    // 虚函数
    virtual void iAmWho() {
        cout << ">>>>>>>i am inline base class<<<<<<" << endl;

    }

    // 内联 + 虚函数
    inline virtual void inlineExpand()
    {
        cout<<">>>>>>i am virtual function can be inline expand<<<<<<"<<endl;
    }
    virtual~ InlineBaseClass(){}
};

class InlineClassImpl : public InlineBaseClass {

public:
    void iAmWho() {
        cout << ">>>>>>>>i am inline impl class<<<<<<" << endl;
    }
    inline  void inlineExpand() override{
        cout<<">>>>>i am Inline Class Impl can be inline expand ? so nope i cannot be expanded <<<<<<"<<endl;
    }
};

int main() {
    School *school = new Class();
    // 虚函数调用取决于类型对象的，而不是指针自身类型
    school->room(); //>>>>>Class combine from many class<<<<

    cout << ">>>>>>>>>>>>>>>>>>>>>>>>华丽的分割线<<<<<<<<<<<<<<<<<<<<<<<" << endl;

    Sample sample;
    Base &b = sample; //引用
    Base *base = &sample; // 指针
    base->fun();//>>>>Sample::fun(), x=10 默认使用的参数为Base中定义的默认参数，即左边
    b.fun();

    User *user = new User(0);
//    user->setId(1);
    user->action();


    cout << ">>>>>>>>>>>>>>>>华丽的分割线<<<<<<<<<<<<<<<<<<<<<<<" << endl;

    PrivateBaseClass *privateBaseClass = new PrivateClassImpl;
    privateBaseClass->fun(); // 如果不讲main函数声明为友元函数，即在main函数中使用一个该类的一个私有函数是无法访问的。
    privateBaseClass->publicFun();// 将基类的方法所属域由私有改为公有，其派生类的继承的方法的作用域为private。这样实现了很友元函数的一样的效果


    cout << ">>>>>>>>>>>>>>>>华丽的分割线<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    // 通过对象实例调用虚函数，因此在编译器时期就确定了实例，因此虚函数可以被内联展开
    InlineBaseClass bn;
    bn.iAmWho();

    // 此处的虚函数inlineExpand(),是通过InlineBaseClass的具体对象（bn)来调用的，因此编译期间就能确定，
    // 所以它是可以是内联的，但最终是否内联取决于编译器
    bn.inlineExpand();
    // 通过指针调用虚函数，呈现多态性，需在运行时期才能确定，因此该虚函数不能被内联展开，
    InlineBaseClass *bba = new InlineClassImpl;
    bba->iAmWho();
    bba->inlineExpand();

    // InlineBaseClass有虚析构函数，所以delete时，会先调用派生类的析构函数，在调用基类的析构函数，防止内存泄漏
    delete bba;


    return 0;
}


