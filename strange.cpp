int baadcommnent() {
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

