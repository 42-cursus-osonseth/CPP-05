CC				= c++

CFLAGS 			= -Wall -Wextra -Werror -g -std=c++98
#-fno-elide-constructors

INCLUDEPATH		= ./Includes

SRCPATH 		= ./

OBJDIR 			= ./obj/

DEPDIR 			= ./dep/

SRCName			= main.cpp Bureaucrat.cpp Form.cpp Exception.cpp

SRCS = $(addprefix $(SRCPATH), $(SRCName))

OBJS = $(patsubst $(SRCPATH)%.cpp, $(OBJDIR)%.o, $(SRCS))

DEPS = $(patsubst $(OBJDIR)%.o, $(DEPDIR)%.d, $(OBJS))

Name = bureaucrat

all: $(OBJDIR) $(DEPDIR) $(Name)

$(OBJDIR) $(DEPDIR):
	@mkdir -p $(OBJDIR) $(DEPDIR)

$(OBJDIR)%.o: $(SRCPATH)%.cpp
	@$(CC) $(CFLAGS) -I$(INCLUDEPATH) -MMD -MP -c $< -o $@

$(Name): $(OBJS)
	$(CC) $(CFLAGS) -o $(Name) $(OBJS)
	@mv obj/*.d dep/

-include $(DEPS)

clean:
	rm -rf obj dep

fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re