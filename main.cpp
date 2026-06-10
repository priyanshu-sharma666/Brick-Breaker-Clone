#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

int main() {

	sf::RenderWindow window(sf::VideoMode(640, 480), "Breaker");
	window.setFramerateLimit(60);


	sf::Font font;
	if (!font.loadFromFile("TTD Compadre-Regular.otf")) {
		std::cout << " Failed to load font\n";
	}

	int score = 0;
	bool gameOver = false;

	//game over text
	sf::Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(48);
	gameOverText.setFillColor(sf::Color::Red);
	gameOverText.setString("GAME OVER");
	gameOverText.setPosition(200.f, 200.f);


	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(24.f);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(10.f, 10.f);
	scoreText.setString("Score: 0");


	//player paddle
	sf::RectangleShape plyrRect(sf::Vector2f(110.f, 15.f));
	plyrRect.setFillColor(sf::Color(85, 70, 60));
	// Positioning it slightly above the bottom boundary so it looks better
	plyrRect.setPosition((window.getSize().x - plyrRect.getSize().x) / 2.f, window.getSize().y - plyrRect.getSize().y - 10.f);


	//ball
	sf::CircleShape ball;
	ball.setRadius(10.f);
	ball.setFillColor(sf::Color::Red);
	ball.setPosition((window.getSize().x - ball.getRadius() * 2.f) / 2.f, 50.f);
	float dx = 5.f; // Slightly tuned speed for smooth calculation
	float dy = 5.f;


	//gameloop
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (gameOver)
		{
			window.clear();
			window.draw(gameOverText);
			window.display();
			continue;
		}


		//ball movement
		ball.move(dx, dy);
		
		// Bottom boundary check
		if (ball.getPosition().y + ball.getRadius() * 2.f > window.getSize().y) {
			gameOver = true;
		}

		//left and right wall
		if (ball.getPosition().x <= 0 || ball.getPosition().x + ball.getRadius() * 2.f >= window.getSize().x) {
			dx = -dx;
		}

		//top wall
		if (ball.getPosition().y <= 0) {
			dy = -dy;
		}

		//paddle collision handling
		if (plyrRect.getGlobalBounds().intersects(ball.getGlobalBounds())) {
			// CRITICAL FIX: Push the ball out of the paddle to prevent getting stuck
			ball.setPosition(ball.getPosition().x, plyrRect.getPosition().y - ball.getRadius() * 2.f);
			
			dy = -std::abs(dy); // Secure bouncing up
			score++;
			scoreText.setString("Score: " + std::to_string(score));
		}

		//player paddle movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && plyrRect.getPosition().x > 0) {
			plyrRect.move(-8.f, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && plyrRect.getPosition().x + plyrRect.getSize().x < window.getSize().x) {
			plyrRect.move(8.f, 0.f);
		}
		

		window.clear();
		window.draw(plyrRect);
		window.draw(ball);
		window.draw(scoreText);
		window.display();
	}
	return 0;
}