cpp_formatter=clang-format
cpp_formatter_options=-style=Google -i

java_formatter=clang-format
java_formatter_options=-style=Google -i

go_formatter=go fmt

python_formatter=autopep8
python_formatter_options=-ai

format:
	@printf "Formatting C++ files... "
	@find . -regex '.*\.\(cpp\|hpp\|cc\|cxx\)' -exec $(cpp_formatter) $(cpp_formatter_options) {} \;
	@printf "done\n"
	@printf "Formatting Java files... "
	@find . -regex '.*\.\(java\)' -exec $(java_formatter) ${java_formatter_options} {} \;
	@printf "done\n"
	@printf "Formatting go files... "
	@find . -regex '.*\.\(go\)' -exec $(go_formatter) {} \;
	@printf "done\n"
	@printf "Formatting Python files... "
	@find . -regex '.*\.\(py\)' -exec $(python_formatter) $(python_formatter_options) {} \;
	@printf "done\n"
