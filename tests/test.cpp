#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stddef.h>
#include "../src/IComponent.hpp"
#include "../src/InputComponent.hpp"
#include "../src/OutputComponent.hpp"
#include "../src/FalseComponent.hpp"
#include "../src/TrueComponent.hpp"
#include "../src/AndComponent.hpp"

Test(basics, input_output)
{
    nts::IComponent *input = new nts::InputComponent("in");
    nts::IComponent *output = new nts::OutputComponent("out");

    input->setLink(1, *output, 1);
    output->setLink(1, *input, 1);
    input->setPinVal(1, nts::Tristate::True);
    input->simulate(1);
    output->simulate(1);
    cr_assert(output->compute(1) == nts::Tristate::True);
}

Test(basics, true_output)
{
    nts::IComponent *input = new nts::TrueComponent("true");
    nts::IComponent *output = new nts::OutputComponent("out");

    input->setLink(1, *output, 1);
    output->setLink(1, *input, 1);
    cr_assert(output->compute(1) == nts::Tristate::True);
}

Test(basics, false_output)
{
    nts::IComponent *input = new nts::FalseComponent("true");
    nts::IComponent *output = new nts::OutputComponent("out");

    input->setLink(1, *output, 1);
    output->setLink(1, *input, 1);
    cr_assert(output->compute(1) == nts::Tristate::False);
}

Test(basics, andgate_output)
{
    // nts::IComponent *input1 = new nts::InputComponent("in1");
    // nts::IComponent *input2 = new nts::InputComponent("in2");
    // nts::IComponent *output = new nts::OutputComponent("out");
    // nts::IComponent *and = new nts::AndComponent("and"); 
    //
    // input1->setLink(1, *and, 1);
    // output->setLink(1, *input, 1);
    // cr_assert(output->compute(1) == nts::Tristate::True);
}
