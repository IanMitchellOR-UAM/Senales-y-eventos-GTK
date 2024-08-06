/**
* Fuente original: https://calcifer.org/documentos/librognome/gtk-basic-example.html
* gcc `pkg-config --cflags gtk+-3.0` gtk-nombre.c -o gtk-nombreEXE `pkg-config --libs gtk+-3.0`
*/

#include <gtk/gtk.h>

// Función de callback para mostrar "Hello World" en la consola
void hello(GtkWidget *widget, gpointer data) {
    g_print("Hello World\n");
}

// Función de callback para manejar el evento de eliminar la ventana
gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
    g_print("Evento de eliminación ocurrido\n");
    // Retorna TRUE para evitar que la ventana se cierre
    return TRUE;
}

// Función de callback para destruir la ventana y salir de la aplicación
void destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *button;

    // Inicializa GTK
    gtk_init(&argc, &argv);

    // Crea una nueva ventana
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Conecta la señal "delete_event" para llamar a la función delete_event
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);

    // Conecta la señal "destroy" para llamar a la función destroy
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);

    // Establece el ancho del borde de la ventana
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Crea un nuevo botón con la etiqueta "Hello World"
    button = gtk_button_new_with_label("Ian Mitchell Ochoa Román");

    // Conecta la señal "clicked" del botón para llamar a la función hello
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(hello), NULL);

    // Conecta la señal "clicked" del botón para destruir la ventana
    g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(window));

    // Agrega el botón a la ventana
    gtk_container_add(GTK_CONTAINER(window), button);

    // Muestra el botón
    gtk_widget_show(button);

    // Muestra la ventana
    gtk_widget_show(window);

    // Entra en el bucle principal de GTK
    gtk_main();

    return 0;
}
