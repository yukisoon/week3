//http://www.glfw.org/documentation.html

#include <GLFW/glfw3.h>

const int width = 640;
const int height = 480;


// color = (red, green, blue)
float *pixels = new float[width * height * 3]; //=malloc

void drawOnePixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width*j) * 3 + 0] = red;
	pixels[(i + width*j) * 3 + 1] = green;
	pixels[(i + width*j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawOnePixel(i, j, red, green, blue);
	}
}

void draw()
{
	const int i_center = 50, j_center = 50;
	const int thickness = 50;

	/*white background*/
	for (int j = 0; j < height; j++)
		for (int i = 0; i < width; i++)
		{
			drawOnePixel(i, j, 1.0f, 1.0f, 1.0f);
		}

	/*사선*/
	drawLine(50, 350, 100, 400, 0.0f, 0.0f, 1.0f);
	drawLine(50, 351, 100, 401, 0.0f, 0.0f, 1.0f);
	drawLine(50, 352, 100, 402, 0.0f, 0.0f, 1.0f);
	drawLine(50, 353, 100, 403, 0.0f, 0.0f, 1.0f);
	drawLine(50, 354, 100, 404, 0.0f, 0.0f, 1.0f);
	drawLine(50, 355, 100, 405, 0.0f, 0.0f, 1.0f);
	drawLine(50, 356, 100, 406, 0.0f, 0.0f, 1.0f);
	drawLine(50, 357, 100, 407, 0.0f, 0.0f, 1.0f);
	drawLine(50, 358, 100, 408, 0.0f, 0.0f, 1.0f);
	drawLine(50, 359, 100, 409, 0.0f, 0.0f, 1.0f);
	drawLine(50, 360, 100, 410, 0.0f, 0.0f, 1.0f);

	/*빈사각형*/
	for (int j = 399; j < 400; j++)//세로
		for (int i = 200; i < 250; i++)//가로
		{
			drawOnePixel(i, j, 1.0f, 0.0f, 0.0f);
		}

	for (int j = 349; j < 350; j++)//세로
		for (int i = 200; i < 250; i++)//가로
		{
			drawOnePixel(i, j, 1.0f, 0.0f, 0.0f);
		}

	for (int j = 350; j < 400; j++)//세로
		for (int i = 249; i < 250; i++)//가로
		{
			drawOnePixel(i, j, 1.0f, 0.0f, 0.0f);
		}

	for (int j = 350; j < 400; j++)//세로
		for (int i = 199; i < 200; i++)//가로
		{
			drawOnePixel(i, j, 1.0f, 0.0f, 0.0f);
		}


	/*채운사각형*/
	for (int j = 350; j < 400; j++)//세로
		for (int i = 300; i < 350; i++)//가로
		{
			drawOnePixel(i, j, 1.0f, 0.0f, 0.0f);
		}


	/*삼각형*/
	drawLine(50, 50, 100, 100, 0.0f, 0.0f, 1.0f);
	drawLine(100, 100, 150, 50, 0.0f, 0.0f, 1.0f);
	drawLine(50, 50, 150, 50, 0.0f, 0.0f, 1.0f);

	/*오각형*/
	drawLine(170, 50, 200, 80, 0.0f, 0.0f, 1.0f);
	drawLine(200, 80, 230, 50, 0.0f, 0.0f, 1.0f);
	drawLine(170, 50, 180, 30, 0.0f, 0.0f, 1.0f);
	drawLine(220, 30, 230, 50, 0.0f, 0.0f, 1.0f);
	drawLine(180, 30, 220, 30, 0.0f, 0.0f, 1.0f);

	/*원*/
	for (int i = 50; i < 100; i++)
		for (int j = 200; j < 250; j = j + 2)
		{
			drawOnePixel(i, j, 1.0f, 0.0f, 0.0f);
		}

	//drawLine(100, 100, 150, 50, 0.0f, 0.0f, 1.0f);


}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		//assign all pixels red color
		draw();

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	delete[] pixels; //=free

	return 0;
}