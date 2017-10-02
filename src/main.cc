#include "swarm.h"
#include "screen.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	Screen screen;
	if (screen.init() == false) {
		cout << "Error in initalizing SDL" << endl;
	}

	Swarm swarm;

	while(true) {
		int elapsed = SDL_GetTicks();
		swarm.update(elapsed);

		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

		const Particle * const pParticles = swarm.getParticles();

		for(int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();
		screen.update();
		if (screen.processEvents() == false)
			break;
	}

	screen.close();

	return 0;
}