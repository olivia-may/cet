#
# cet - C-a Esperanta Tradukisto
# Copyright (C) 2023 Olivia May - olmay@tuta.io
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.
#

CC=gcc

# what im calling this i guess haha
PROGRAM_NAME=cet

.PHONY=clean run install uninstall

$(PROGRAM_NAME):
	$(CC) main.c -o $(PROGRAM_NAME).o

saluton_mondo: $(PROGRAM_NAME)
	./$(PROGRAM_NAME).o saluton_mondo.ce > translated.c
	$(CC) translated.c -o translated.o
	./translated.o

clean:
	rm -f *.out *.o translated.c

run: $(PROGRAM_NAME)
	./$(PROGRAM_NAME).o

### Root access needed ###
install: $(PROGRAM_NAME)
	install -D $(PROGRAM_NAME).o /usr/local/bin/$(PROGRAM_NAME)

uninstall:
	rm /usr/local/bin/$(PROGRAM_NAME)
### ###
