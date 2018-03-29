
#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <gsl/gsl.h>


class electron_struct
{

    public:

    electron_struct(const double ke, const double r)
        : ke{ke}
        , r{r}
    {
    }

    double ke;
    double r;
    //double t;
};

double time_integral_error_function(const double x, const double A, const double B)
{
    const double arg{std::sqrt(A / B - std::log(x))};
    const double ret{gsl_sf_erf(arg)};
    return ret;
}

double time_integral(const double initial_time, const double final_time)
{
    // initial and final time constants
    const double t_A{initial_time};
    const double t_B{final_time};


    // intrinsic function constants
    const double e{};
    const double V0{};
    const double R_A{};
    const double R_B{};
    const double m{};
    const double KE_0;

    // derived function constants
    const double F1{std::log(R_B) - std::log(R_A)};
    const double F2{e * V0};
    const double F3{F2 / F1};
    const double F4{2.0 / m};
    const double F5{F4 * F2};
    const double F6{F5 / F1};

    // function parameter constants
    const double A{F4 * (KE_0 + F3 * std::log(r0))};
    const double B{F6 * std::log(r)};

    const double E_A{time_integral_error_function(t_A, A, B)};
    const double E_B{time_integral_error_function(t_B, A, B)};

    const double MULT{-std::sqrt(M_PI / B) * std::exp(A / B)};

    const double ret{MULT * (E_B - E_A)};

    return ret;
}

int main(int argc, char* argv[])
{

    // random number generation
    std::random_device rd;
    std::mt19937_64 gen;
    std::uniform_real_distribution<double> dis;
    std::exponential_distribution<double> dis_exp;

    // storage for electron structs
    std::vector<electron_struct> electron;

    // initial x, y position of event, r coordinate of event
    double x{dis(gen())};
    double y{dis(gen())};
    double r{std::sqrt(x * x + y * y)};
    double t{0.0};

    electron.emplace_back(0.0, r);

    // mean free path constant
    const double MEAN_FREE_PATH{0.01};
    const double lambda{1.0 / MEAN_FREE_PATH};

    // random length electron moves before collision
    const double d_x{dis_exp(gen())};

    const double r_prev{electron[index].r};
    double r_next{r_prev - d_x};

    if(r_next <= 0.0)
    {
        d_t{time_integral(initial position, final position)};
    }


    return 0;
}
