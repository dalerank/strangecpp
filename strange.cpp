// Will Geralt get coins?
class Witcher {
  int i;

public:
  virtual int TakeCoins(int coins) { return i += coins; }
};

int main() {
  Witcher *geralt = new Witcher();

  memset(geralt, 0, sizeof(Witcher));

  std::cout << geralt->TakeCoins(100);
  return 0;
}
// Witcher always take coins. 

// Which one word need to change that fix this code?
struct Foo {
  void *foo;
  struct foo *next;
};

static Foo foos;
static std::mutex m;

void consume_list_element(const std::condition_variable &condition) {
  std::unique_lock<std::mutex> lk(m);

  if (foos.next == nullptr) {
    condition.wait(lk);
  }

  // Proceed when condition holds.
}

// What will print this function?
int main() {
  const char *str = nullptr;
  {
    const char tmpstr1[] = "Goodbye world";
    str = tmpstr1;
  }
  printf("%s", str ? str : "Hello world"); 
  return 0;
}
// https://godbolt.org/z/Wd4GMx6se
// https://godbolt.org/z/9ovx8q59j

// What will print this function?
struct T {
    ~T() { printf("Goodbye world"); }
};

int main() {
  T *bar = new T;
  std::shared_ptr<T> p1(bar);
  std::shared_ptr<T> p2(bar);

  return 0;
}

// What will print this function?
int main() {
  const bool x = 1;
  auto str = std::string(x ? "Hello world" : "Goodbye world").c_str();
  printf("%s", str);
  return 0;
}
// https://godbolt.org/z/arMhTqcdn

// What will this function print?
#include <cstdio>

void helloworld() {
    printf("Hello world!");
}

int main() {
    while (1) {
        ;
    }
    helloworld();
    return 0;
}

void goodbyeworld() {
    printf("Goodbye world!");
}
// https://godbolt.org/z/h7WooW6PE

// What will return this function?
int pockets[] = { 0, 1 };
int index = 0;

int get_money(int index, const int *pockets) {
  int a = index + pockets[++index];
  // ...

  return a;
}

// What will this function print?
// c++23
int main() {
  std::vector a{0, 1, 1, 0};
  std::erase(a, a[0]);
  println("{}", a);
}
// https://godbolt.org/z/zf3G5e9ns

// Which lambda corresponds to which programming language?
(<0)                              // 1:  H....
_ < 0                             // 2:  S....
&(&1 < 0)                         // 3:  E....
|e| e < 0                         // 4:  R....
{ $0 < 0 }                        // 5:  S....
#(< % 0)                          // 6:  C....
_1 < 0                            // 7:  B....
{ |e| e < 0 }                     // 8:  R....
{ e in e < 0 }                    // 9:  S....
lambda e: e < 0                   // 10: P....
[] { return 1; }                  // 11: C....
\(e) e < 0                        // 11: R....
{ it < 0 }                        // 12: K....
e -> e < 0                        // 13: J....
fn x -> x < 0 end                 // 14: E....
(lambda (x) (< x 0))              // 15: R....
{ e -> e < 0 }                    // 16: K....
fun e -> e < 0                    // 17: F....
[](auto e) { return e < 0; }      // 18: C....
std::bind(std::less{}, _1, 0)     // 19: C....
func(e int) bool { return e < 0 } // 20: G....
e => e < 0                        // 21: C....
\e -> e < 0                       // 22: H....
(λ (x) (< x 0))                   // 23: R....

// What this function will print?
#include <iostream>

typedef void (*Function1)();

static Function1 Function2 = nullptr;
const char *result = "Hello World";

static void FunctionPrint() {
  result = "Goodbye world";
}

void NeverCalled() {
  Function2 = FunctionPrint;  
}

int main() {
  Function2();  
  printf("%s", result);

  return 0;
}
// https://godbolt.org/z/GKhq74j31

// bug in ps5 sdk monotonic_buffer_resource
protected:
	virtual void *do_allocate(size_t _Bytes, size_t _Bound)
	{	// allocate from blocks
	....

	for (; ; )
		{	// find aligned space, or add more blocks
		for (_Mylist::iterator _It = _Free_space.begin();
			++_It != _Free_space.end(); )  // <<<<<<<<<<<<<<<<<<<< miss buffer for work
			{
			uintptr_t _Current_offset_addr = (uintptr_t)(_It->_Ptr + _It->_Offset);
			char *_Next_aligned_addr =
				(char *)((_Current_offset_addr + (_Bound - 1)) & ~(_Bound - 1));
			if (_Next_aligned_addr + _Bytes <= _It->_Ptr + _It->_Bytes)
				{	// room for aligned storage, return its address
				_It->_Offset = (_Next_aligned_addr + _Bytes) - _It->_Ptr;
				return (_Next_aligned_addr);
				}
			}

		    ....
		}
	}

// Just to wake up, what this function print?
int main() {
    struct { auto operator,(char $) { (char&)*this = $; return *this; } } $;
    printf("%d", ($, 42, 45, 41, 55));
    printf("%d", $, 42, 45, 41, 55);
    return 0;
}

// what this function will print?
volatile int drive = 2;

int main()
{
    if (drive == 2) // we just want handle this logic on disk c:\
        printf("Hello world");  

    printf("Goodbye world");
    return 0;
}

// What from this code can be compiled?
void f(void);

template<typename T>
auto ft(T t) { return t(); }

int t() {
    void (*f1)(void) = f;
    void (*f2)(void) = *f;
    void (*f3)(void) = &f;
    void (*f4)(void) = ******f;
    void (*f5)(void) = &***********f;
    void (*f6)(void) = ***&***f;
    void (*f7)(void) = &**&***&***&f;
    auto f8 = f();
    auto f9 = [] { return f(); };
    [] { return f(); } ();
    ft(f);
    return 0;
}

// Can c++ compile urls?
int main() {
    http://www.godbolt.org
    https://www.godbolt.org
    ftp://123.oldstrage.me/data
    return (int)"Can I compile urls?";
}

// baad comment
int baadcomment() {
    std::string hello_world = "hello world";
    if (hello_world.compare("hello world‮ ⁦// Check this is correct⁩ ⁦"))
    {
        printf("goodbye world");
    }
}

// This code was used in the Unity 2014 engine to control the rotation of objects using a gizmo (a control element,
// usually in the form of three circles, that allows you to rotate an object in the scene). In this case, the setDeltaPitch 
// function is applied to change the pitch angle of the object relative to its vertical axis. At angles close to 0 
// (depending on the editor settings), it would simply flip the object upside down, which really annoyed the level designers. First one here ^)
void	UObject::setDeltaPitch(const UMatrix &gizmo) {       
		//....

		if (_fpzero(amount, eps))
			return

		rotateAccum.setAnglesXYZ(axis);
        //....
}

// There can be issues when working with two or more threads accessing either of the variables a/b. 
// This error was present in the CryTek engine when synchronizing the state of vehicles over the network, which resulted in 
// jerks and teleports when driving a car in the multiplayer mode of FarCry 1. The more players were on the map, the higher 
// the probability of teleportation for the last player. With 16 players on the map, the last player would consistently teleport 
// if they were using a vehicle.
struct X {
  int a : 2;
  int b : 2;
} x;

Thread 1:
void foo() { x.a = 1 }

Thread 2:
void boo() { x.b = 1 }

// Functions can be defined to accept more arguments at the call site than are specified in the declaration. 
// Such functions are called variadic functions. C++ provides two mechanisms to define a variadic function: a template with a 
// variable number of parameters and the use of an ellipsis in the C style as the final parameter declaration. A very unpleasant 
// behavior was encountered in the popular FMOD Engine sound library. I present the code as it appeared in the source files; 
// it seems the developers wanted to save on templates. 
int add(int first, int second, ...) {
  int r = first + second; 
  va_list va;
  va_start(va, second);
  while (int v = va_arg(va, int)) {
    r += v;
  }
  va_end(va);
  return r;
}

int main() {
    int i = add(0, 1);
    std::cout << i;
}

// This code was dragged into the repository in the Friday evening and seems somebody slipped on review. It took an hours to
// figure out the strange behavior in real app. The author was sent to make coffee for everyone and was banned from
// committing on Friday evenings. It sample, but can you catch the error?

// begin a.h
#ifndef A_HEADER_FILE
#define A_HEADER_FILE
  
namespace {
int v;
}
  
#endif // A_HEADER_FILE
//end a.h

// Here, we didn’t lock anything, even though at first glance it seemed like we did. This code was found in unity engine
// in certain places when working with resources, which led to strange crashes
static std::mutex m;
static int shared_resource = 0;
 
void increment_by_42() {
  std::unique_lock<std::mutex>(m);
  shared_resource += 42;
}

// Here’s an example of code that was randomly failing in the release build on different compilers, which was used to calculate 
// checksums in PathEngine. The solution for the PlayStation contained a specific flag that masked the issue, while it was missing 
// on the other platforms. The bug was discovered when we tried to build the library using Clang on PC

struct AreaCrc32 {
  unsigned char buffType = 0;
  int crc = 0;
};

AreaCrc32 s1 {};
AreaCrc32 s2 {};

void similarArea(const AreaCrc32 &s1, const AreaCrc32 &s2) {
  if (!::memcmp(&s1, &s2, sizeof(AreaCrc32))) {
    // ...
  }
}

// Often case in review, real code from some engine (such it was in 2016 year) It was class for work with callbacks
// where error?

struct S { S(const S *) noexcept; /* ... */ };
  
class T {
  int n;
  S *s1;
  
public:
  T(const T &rhs) : n(rhs.n),
                    s1(rhs.s1 ? new S(rhs.s1) : nullptr) {}
  ~T() { delete s1; }
  
  // ...
  
  T& operator=(const T &rhs) {
    n = rhs.n;
    delete s1;
    s1 = new S(rhs.s1);
    return *this;
  }
};

// What from this will not compile and work on c++?
int main()
{
    // 0
    enum state {
        waiting = 'WAIT',
        running = 'RUN!',
        stopped = 'STOP',
    };
    printf("state = %s\n", &(state{waiting}));
    
    // 1
    char (*ap3)[90][90] = malloc(sizeof *ap3);
    printf("sizeof(ap3) = %d\n", (int)sizeof *ap3);
    
    // 2
    constexpr int n = 0xff;
    int (*ap4)<:n:> = malloc(sizeof *ap4);
    
    // 3
    struct bar {
        unsigned char x : 5;
        unsigned short  : 0;
        unsigned char y : 7;
    };
    printf("sizeof(bar) = %d\n", (int)sizeof(bar));
    
    // 4
    int nn = 10;
    while (nn --> 0) {
        printf("%d\n", nn);
    }
    
    // 5
    100??(*ap4??) or_eq 7;
    printf("%d\n", *(*ap4 + 100));

    return 0;
}

// Can this code works?
struct A {
    int x = 0;
    void bar() { std::cout << "bar" << std::endl; }
};

int  main() {
    A *a = nullptr;
    a->bar();
}

// What will be the output of the program?
void sayHello() {
    std::cout << "Hello, World!\n";
}
void sayНello() {
    std::cout << "Goodbye, World!\n";
}
int main() {
    sayНello();
    return 0;
}

// What this function will print?
int abs_legs(int my_legs) {
  if (my_legs < 0) {
    return -my_legs;
  }
}

int main() {
    volatile int legs = 4;
    printf("%d", abs_legs(legs));
}
// https://godbolt.org/z/G6xGn7P6s
