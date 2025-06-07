public class Email {
    private String email; 
    public Email(String email) {
        this.email = email;
    };
    
    public boolean validateEmail() throws InvalidDomainException, InvalidEmailException{
        if (email.isEmpty()) throw new InvalidEmailException("Email tidak boleh kosong");
        if (!email.contains("@")) throw new InvalidEmailException("Email harus mengandung tepat satu buah @");
        if (email.indexOf("@") != email.lastIndexOf("@")) throw new InvalidEmailException("Email harus mengandung tepat satu buah @");
        if (email.startsWith("@")) throw new InvalidEmailException("@ tidak boleh di awal email");
        
        String domain = email.substring(email.indexOf("@") + 1);
        if (domain.indexOf(".") == -1) throw new InvalidDomainException();
        if (domain.indexOf(".") != domain.lastIndexOf(".") ) throw new InvalidDomainException();
        if (domain.startsWith(".") || domain.endsWith(".")) throw new InvalidDomainException();
        if (domain.isEmpty()) throw new InvalidDomainException();
        return true;
    }

}

class InvalidEmailException extends Exception {
    public InvalidEmailException(String message) {
        super(message);
    }
}

class InvalidDomainException extends Exception {
    public String getMessage() {
        // Implementasi custom message InvalidDomainException
        // Return pesan multak berisi: "Email harus memiliki domain yang valid
        return "Email harus memiliki domain yang valid";
    }
}