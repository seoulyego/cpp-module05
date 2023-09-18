#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form {
    private:
        const std::string target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(ShrubberyCreationForm& object);
        ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& object);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(const std::string target);
        const std::string   getTarget() const;
        void                execute(Bureaucrat const& executor) const;
};

#endif  // SHRUBBERYCREATIONFORM_HPP
