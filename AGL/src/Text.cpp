#include "../include/Text.hpp"

void agl::Text::setFont(Font *font)
{
	this->font = font;
	this->height = font->getHeight();

	charBox.setTexture(font->getTexture());
	charBox.setColor(agl::Color::White);
}

void agl::Text::setText(const std::string& str)
{
	delete[] glyph;
	
	length = str.length();
	glyph = new Glyph*[length];

	width = 0;

	for(int i = 0; i < length; i++)
	{
		Glyph *g = font->getGlyph(str[i]);

		width += g->advance;
		glyph[i] = font->getGlyph(str[i]);
    // printf("add glyph: value =%c\n", str[i]);
    // printf("         : size=%d, %d\n", g->size.x, g->size.y);
    // printf("         : scale=%f, %f\n", g->scale.x, g->scale.y);
    // printf("         : pos=%f, %f\n", g->position.x, g->position.y);
    // printf("         : bearing=%d, %d\n", g->bearing.x, g->bearing.y);
    // printf("         : advance =%d\n", g->advance);
    
	}
}

void agl::Text::setScale(float scale)
{
	this->scale = scale;
}

void agl::Text::setPosition(agl::Vec<float, 3> position)
{
	this->position = position;
}

void agl::Text::setColor(agl::Color color)
{
	charBox.setColor(color);
}

void agl::Text::clearText()
{
	delete[] glyph;
	glyph = nullptr;
	length = 0;
}

agl::Glyph *agl::Text::getGlyph(int i)
{
	return glyph[i];
}

agl::Rectangle *agl::Text::getCharBox()
{
	return &charBox;
}

int agl::Text::getLength()
{
	return length;
}

agl::Font* agl::Text::getFont()
{
	return font;
}

int agl::Text::getHeight()
{
	return height;
}

agl::Vec<float, 3> agl::Text::getPosition()
{
	return position;
}

float agl::Text::getScale()
{
	return scale;
}

float agl::Text::getWidth()
{
	return width;
}
