#include <iostream>
#include <unordered_map>

struct shared_state
{
    std::string brand_;
    std::string model_;
    std::string color_;

    shared_state(const std::string& brand, const std::string& model, const std::string& color)
        : brand_(brand), model_(model), color_(color)
    {
    }

    friend std::ostream& operator<<(std::ostream& os, const shared_state& ss)
    {
        return os << "[ " << ss.brand_ << " , " << ss.model_ << " , " << ss.color_ << " ]";
    }
};

struct unique_state
{
    std::string owner_;
    std::string plates_;

    unique_state(const std::string& owner, const std::string& plates) : owner_(owner), plates_(plates) {}

    friend std::ostream& operator<<(std::ostream& os, const unique_state& us)
    {
        return os << "[ " << us.owner_ << " , " << us.plates_ << " ]";
    }
};

class flyweight
{
private:
    shared_state* shared_state_;

public:
    flyweight(const shared_state* shared_st) : shared_state_(new shared_state(*shared_st)) {}
    flyweight(const flyweight& other) : shared_state_(new shared_state(*other.shared_state_)) {}
    ~flyweight() { delete shared_state_; }
    shared_state* shared_st() const { return shared_state_; }
    void Operation(const unique_state& unique_st) const
    {
        std::cout << "flyweight: Displaying shared (" << *shared_state_ << ") and unique (" << unique_st
                  << ") state.\n";
    }
};

class flyweight_factory
{
private:
    std::unordered_map<std::string, flyweight> flyweights_;
    std::string GetKey(const shared_state& ss) const { return ss.brand_ + "_" + ss.model_ + "_" + ss.color_; }

public:
    flyweight_factory(std::initializer_list<shared_state> share_states)
    {
        for (const shared_state& ss : share_states)
        {
            this->flyweights_.insert(std::make_pair<std::string, flyweight>(this->GetKey(ss), flyweight(&ss)));
        }
    }

    flyweight get_flyweight(const shared_state& shared_st)
    {
        std::string key = this->GetKey(shared_st);
        if (this->flyweights_.find(key) == this->flyweights_.end())
        {
            std::cout << "flyweight_factory: Can't find a flyweight, creating new one.\n";
            this->flyweights_.insert(std::make_pair(key, flyweight(&shared_st)));
        }
        else
        {
            std::cout << "flyweight_factory: Reusing existing flyweight.\n";
        }
        return this->flyweights_.at(key);
    }
    void ListFlyweights() const
    {
        size_t count = this->flyweights_.size();
        std::cout << "\nflyweight_factory: I have " << count << " flyweights:\n";
        for (std::pair<std::string, flyweight> pair : this->flyweights_)
        {
            std::cout << pair.first << "\n";
        }
    }
};

void AddCarToPoliceDatabase(flyweight_factory& ff,
                            const std::string& plates,
                            const std::string& owner,
                            const std::string& brand,
                            const std::string& model,
                            const std::string& color)
{
    std::cout << "\nClient: Adding a car to database.\n";
    const flyweight& flyw = ff.get_flyweight({brand, model, color});
    flyw.Operation({owner, plates});
}

int main()
{
    flyweight_factory* factory = new flyweight_factory({{"Chevrolet", "Camaro2018", "pink"},
                                                        {"Mercedes Benz", "C300", "black"},
                                                        {"Mercedes Benz", "C500", "red"},
                                                        {"BMW", "M5", "red"},
                                                        {"BMW", "X6", "white"}});
    factory->ListFlyweights();

    AddCarToPoliceDatabase(*factory, "CL234IR", "James Doe", "BMW", "M5", "red");
    AddCarToPoliceDatabase(*factory, "CL234IR", "James Doe", "BMW", "X1", "red");
    factory->ListFlyweights();
    delete factory;

    return 0;
}
