#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Engine.h"


void load()
{
	
}

int main(int, char*[]) {
	dae::Engine engine("../Data/");
	engine.Run(load);
    return 0;
}