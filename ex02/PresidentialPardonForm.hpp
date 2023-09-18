#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {
    private:
        const std::string target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(PresidentialPardonForm& object);
        PresidentialPardonForm&  operator=(const PresidentialPardonForm& object);
        ~PresidentialPardonForm();

        PresidentialPardonForm(const std::string target);
        const std::string   getTarget() const;
        void                execute(Bureaucrat const& executor) const;
};

#endif  // PRESIDENTIALPARDONFORM_HPP

