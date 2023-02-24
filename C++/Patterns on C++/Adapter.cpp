#include <iostream>
#include <memory>
#include <stdio.h>
#include <string>

using namespace std;

class shape
{
public:
    shape() = default;
    virtual ~shape() = default;
    virtual string bounding_box() const { return string("shape bounding_box coord " + to_string(1)); }
};

class text_view
{
public:
    text_view() = default;
    virtual ~text_view() {};

    int get_view_coord() const { return 1; }
    virtual bool is_bad_view() const { return false; }
};

class text_shape_adapter : private text_view, public shape
{
public:
    text_shape_adapter() = default;

    virtual string bounding_box() const override
    {
        return string("text_shape_adapter coord " + to_string(get_view_coord()));
    }

    virtual bool is_bad_view() const override { return text_view::is_bad_view(); }
};

class text_shape_object_adapter : public shape
{
public:
    text_shape_object_adapter() = default;

    string bounding_box() const
    {
        return string("text_shape_object_adapter coord " + to_string(_text->get_view_coord()));
    }
    
    bool is_bad_view() const { return _text->is_bad_view(); }

private:
    unique_ptr<text_view> _text;
};

int main()
{
    unique_ptr<text_shape_adapter> default_adapter = make_unique<text_shape_adapter>();
    unique_ptr<text_shape_object_adapter> object_adapter = make_unique<text_shape_object_adapter>();

    std::cout << "default_adapter: " << default_adapter->bounding_box() << std::endl;
    std::cout << "object_adapter: " << default_adapter->bounding_box() << std::endl;

    return 0;
}