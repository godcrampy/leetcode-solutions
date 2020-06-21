cpp_formatter=clang-format
cpp_formatter_options=-style=Google -i

# https://github.com/google/google-java-format
java_formatter=java -jar /opt/google-java-format-1.8-all-deps.jar
java_formatter_options=-i

go_formatter=go fmt

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
