//
// Created by god on 2021/12/4.
//

#include "main_window.h"

GtkWidget *create_Enter_window() //创建进入窗口
{
    GtkBuilder *builder; //新建一个GtkBuilder对象用于读取GtkBuilder界面文件
    GtkWidget *Enter_window;
    GtkWidget *Enter_button;
    GtkWidget *Exit_button;
    GtkWidget *about_button;

    // gtk_init(&argc,&argv);
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "Enter_window.glade",
                              NULL); //从glade获取控件

    Enter_window =
            GTK_WIDGET(gtk_builder_get_object(builder, "Enter_window")); //获取主窗体
    // gtk_window_set_icon(GTK_WINDOW(Enter_window),
    // create_pixbuf("addressbook.png"));//设置软件图标
    gtk_window_set_title(GTK_WINDOW(Enter_window), "Huffman"); //设置主窗口标题
    Enter_button = GTK_WIDGET(
            gtk_builder_get_object(builder, "Enter_button")); //获取主窗口中的进入按钮
    Exit_button = GTK_WIDGET(
            gtk_builder_get_object(builder, "Exit_button")); //获取主窗口中的退出按钮
    about_button = GTK_WIDGET(
            gtk_builder_get_object(builder, "About_button")); //获取主窗口中的退出按钮
    gtk_widget_set_opacity(Enter_window, 0.2);
    // set_widget_font_size(Enter_button,50,TRUE);//改变控件字体大小
    //  PangoFontDescription *font_desc =
    //  pango_font_description_from_string("Sans");
    //  pango_font_description_set_size (font_desc, 15 * PANGO_SCALE);

    // gtk_widget_modify_font (GTK_WIDGET(Enter_button),  font_desc);
    // pango_font_description_free (font_desc);

    g_signal_connect(Enter_window, "destroy", G_CALLBACK(gtk_main_quit),
                     NULL); //设置主窗口关闭信号链接
    g_signal_connect(Enter_button, "clicked", G_CALLBACK(on_Enter_button_clicked),
                     Enter_window); //设置“进入系统”按钮的回调函数
    g_signal_connect(Exit_button, "clicked", G_CALLBACK(gtk_main_quit),
                     NULL); //设置“退出按钮”的连接动作
    g_signal_connect(about_button, "clicked", G_CALLBACK(on_About_button_clicked),
                     Enter_window);
    return Enter_window;
}

void on_Enter_button_clicked(GtkWidget *button, gpointer window) {
    gtk_widget_hide(GTK_WIDGET(window));
    gtk_widget_show_all(create_main_window());
}

void on_About_button_clicked(GtkWidget *button, gpointer window) {}

/**
 * 创建主系统窗口
 * @return
 */
GtkWidget *create_main_window() {
    GtkBuilder *builder; //新建一个GtkBuilder对象用于读取GtkBuilder界面文件
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "main_window.glade", NULL); //从glade获取控件
    GtkWidget *main_window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window")); //获取系统窗体
//      gtk_window_set_icon(GTK_WINDOW(main_window),create_pixbuf("addressbook.png"));
    GtkWidget *encode_button = GTK_WIDGET(gtk_builder_get_object(builder, "encode_button")); //获取系统窗口中的“编码”按钮
    GtkWidget *decode_button = GTK_WIDGET(gtk_builder_get_object(builder, "decode_button")); //获取系统窗口中的“解码”按钮
    GtkWidget *system_exit_button = GTK_WIDGET(gtk_builder_get_object(builder, "Exit_system")); //获取系统窗口中的“退出系统”按钮
    // set_widget_font_size(Enter_button,50,True);//改变控件字体大小

    gtk_window_set_title(GTK_WINDOW(main_window), "Huffman编译码器"); //设置系统窗口标题
    g_signal_connect(encode_button, "clicked", G_CALLBACK(on_encode_button_clicked), main_window);
    g_signal_connect(decode_button, "clicked", G_CALLBACK(on_decode_button_clicked), main_window);
    g_signal_connect(system_exit_button, "clicked", G_CALLBACK(gtk_main_quit), NULL); //设置“退出按钮”的连接动作
    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL); //设置系统窗口关闭信号链接


    // gtk_builder_connect_signals(builder,NULL);
    // g_object_unref(main_window);
    // g_signal_connect(Exit_button,"clicked",G_CALLBACK(gtk_main_quit),NULL);//设置“退出按钮”的连接动作
    // gtk_widget_show_all(main_window);
    // gtk_main();

    // window_test = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // gtk_widget_show(window_test);
    // gtk_main();
    // return 0;
    return main_window;
}

void on_encode_button_clicked(GtkWidget *button, gpointer window) {
    gtk_widget_hide(GTK_WIDGET(window));
    gtk_widget_show_all(create_encode_window());
}

void on_decode_button_clicked(GtkWidget *button, gpointer window) {
    gtk_widget_hide(GTK_WIDGET(window));
    gtk_widget_show_all(create_decode_window());
}

GtkWidget *create_encode_window() {
    GtkBuilder *builder;
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "encode_window.glade", NULL); //从glade获取控件
    GtkWidget *encode_window = GTK_WIDGET(gtk_builder_get_object(builder, "encode_window")); //获取系统窗体
//      gtk_window_set_icon(GTK_WINDOW(main_window),create_pixbuf("addressbook.png"));
    GtkWidget *encode_entry = GTK_WIDGET(gtk_builder_get_object(builder, "encode_entry"));
    GtkWidget *text_scrolled_window = GTK_WIDGET(gtk_builder_get_object(builder, "text_scrolled_window"));
    GtkWidget *text_view = GTK_WIDGET(gtk_builder_get_object(builder, "text_view"));
    GtkWidget *import_button = GTK_WIDGET(gtk_builder_get_object(builder, "import_button"));
    GtkWidget *export_button = GTK_WIDGET(gtk_builder_get_object(builder, "export_button"));
    // set_widget_font_size(Enter_button,50,True);//改变控件字体大小

    gtk_window_set_title(GTK_WINDOW(encode_window), "Huffman编码器"); //设置系统窗口标题
    g_signal_connect(encode_entry, "activate", G_CALLBACK(on_encode_entry_activate), encode_window);
    g_signal_connect(import_button, "clicked", G_CALLBACK(on_encode_import_button_clicked), encode_window);
    g_signal_connect(export_button, "clicked", G_CALL BACK(on_encode_export_button_clicked), encode_window);
    g_signal_connect(encode_window, "destroy", G_CALLBACK(gtk_main_quit), NULL); //设置系统窗口关闭信号链接
    return encode_window;

}

void on_encode_entry_activate(GtkWidget *entry, gpointer window) {

}

void on_encode_import_button_clicked(GtkWidget *button, gpointer window) {

}

void on_encode_export_button_clicked(GtkWidget *button, gpointer window) {

}

GtkWidget *create_decode_window() {
    GtkBuilder *builder;
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "decode_window.glade", NULL); //从glade获取控件
    GtkWidget *decode_window = GTK_WIDGET(gtk_builder_get_object(builder, "decode_window")); //获取系统窗体
//      gtk_window_set_icon(GTK_WINDOW(main_window),create_pixbuf("addressbook.png"));
    GtkWidget *decode_entry = GTK_WIDGET(gtk_builder_get_object(builder, "decode_entry"));
    GtkWidget *text_scrolled_window = GTK_WIDGET(gtk_builder_get_object(builder, "text_scrolled_window"));
    GtkWidget *text_view = GTK_WIDGET(gtk_builder_get_object(builder, "text_view"));
    GtkWidget *import_button = GTK_WIDGET(gtk_builder_get_object(builder, "import_button"));
    GtkWidget *export_button = GTK_WIDGET(gtk_builder_get_object(builder, "export_button"));
    // set_widget_font_size(Enter_button,50,True);//改变控件字体大小

    gtk_window_set_title(GTK_WINDOW(decode_window), "Huffman编码器"); //设置系统窗口标题
    g_signal_connect(decode_entry, "activate", G_CALLBACK(on_decode_entry_activate), decode_window);
    g_signal_connect(import_button, "clicked", G_CALLBACK(on_decode_import_button_clicked), decode_window);
    g_signal_connect(export_button, "clicked", G_CALLBACK(on_decode_export_button_clicked), decode_window);
    g_signal_connect(decode_window, "destroy", G_CALLBACK(gtk_main_quit), NULL); //设置系统窗口关闭信号链接
}

void on_decode_entry_activate(GtkWidget *entry, gpointer window) {

}

void on_decode_import_button_clicked(GtkWidget *button, gpointer window) {

}

void on_decode_export_button_clicked(GtkWidget *button, gpointer window) {

}