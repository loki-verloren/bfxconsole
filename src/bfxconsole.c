/* bfxconsole.c generated by valac 0.30.1, the Vala compiler
 * generated from bfxconsole.vala, do not modify */

/* bfxconsole.vala
 *
 * License Notice
 *
 * License means permission from a privileged party to do something that would
 * otherwise be a crime, upon their property. This document sits upon your
 * property and you granted licence to its presence there by placing it there.
 *
 * Copyright is nothing more than a monopoly grant privilege, and I don't
 * acknowledge any monopoly other than of a natural person upon their property.
 *
 * Thus since this is now your property, if it messes your shit up, that's not
 * my problem, I am just a simple program writer, and I didn't ask you to
 * place this file upon your computer, or any derivative of this file such as
 * a compiled version that you can run on your computer.
 *
 * Since it is currently residing on your property, you are free to do whatever
 * you want with this file, with no restrictions.
 *
 * The fact that I have to explain these things is sad.
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <libsoup/soup.h>


#define TYPE_BFXCONSOLE (bfxconsole_get_type ())
#define BFXCONSOLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_BFXCONSOLE, bfxconsole))
#define BFXCONSOLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_BFXCONSOLE, bfxconsoleClass))
#define IS_BFXCONSOLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_BFXCONSOLE))
#define IS_BFXCONSOLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_BFXCONSOLE))
#define BFXCONSOLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_BFXCONSOLE, bfxconsoleClass))

typedef struct _bfxconsole bfxconsole;
typedef struct _bfxconsoleClass bfxconsoleClass;
typedef struct _bfxconsolePrivate bfxconsolePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _Block1Data Block1Data;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _bfxconsole {
	GtkApplication parent_instance;
	bfxconsolePrivate * priv;
};

struct _bfxconsoleClass {
	GtkApplicationClass parent_class;
};

struct _bfxconsolePrivate {
	GSettings* settings;
	GtkApplicationWindow* window;
};

struct _Block1Data {
	int _ref_count_;
	bfxconsole* self;
	GtkButton* setkeys;
	GtkEntry* apikey;
	GtkEntry* apisecret;
};


static gpointer bfxconsole_parent_class = NULL;

GType bfxconsole_get_type (void) G_GNUC_CONST;
#define BFXCONSOLE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_BFXCONSOLE, bfxconsolePrivate))
enum  {
	BFXCONSOLE_DUMMY_PROPERTY
};
bfxconsole* bfxconsole_new (void);
bfxconsole* bfxconsole_construct (GType object_type);
void bfxconsole_bfx_settings (bfxconsole* self);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
static void __lambda4_ (Block1Data* _data1_);
static void ___lambda4__gtk_editable_changed (GtkEditable* _sender, gpointer self);
static void __lambda5_ (Block1Data* _data1_);
static void ___lambda5__gtk_editable_changed (GtkEditable* _sender, gpointer self);
static void __lambda6_ (Block1Data* _data1_);
static void ___lambda6__gtk_button_clicked (GtkButton* _sender, gpointer self);
static gboolean bfxconsole_apikeys_are_set (bfxconsole* self);
static void bfxconsole_real_activate (GApplication* base);
gint bfxconsole_main (gchar** args, int args_length1);
static void bfxconsole_finalize (GObject* obj);


bfxconsole* bfxconsole_construct (GType object_type) {
	bfxconsole * self = NULL;
	self = (bfxconsole*) g_object_new (object_type, "application-id", "org.ascension.bfxconsole", "flags", G_APPLICATION_FLAGS_NONE, NULL);
	return self;
}


bfxconsole* bfxconsole_new (void) {
	return bfxconsole_construct (TYPE_BFXCONSOLE);
}


static Block1Data* block1_data_ref (Block1Data* _data1_) {
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}


static void block1_data_unref (void * _userdata_) {
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		bfxconsole* self;
		self = _data1_->self;
		_g_object_unref0 (_data1_->apisecret);
		_g_object_unref0 (_data1_->apikey);
		_g_object_unref0 (_data1_->setkeys);
		_g_object_unref0 (self);
		g_slice_free (Block1Data, _data1_);
	}
}


static void __lambda4_ (Block1Data* _data1_) {
	bfxconsole* self;
	gboolean _tmp0_ = FALSE;
	guint _tmp1_ = 0U;
	guint _tmp2_ = 0U;
	self = _data1_->self;
	_tmp1_ = gtk_entry_get_text_length (_data1_->apikey);
	_tmp2_ = _tmp1_;
	if (_tmp2_ == ((guint) 43)) {
		guint _tmp3_ = 0U;
		guint _tmp4_ = 0U;
		_tmp3_ = gtk_entry_get_text_length (_data1_->apisecret);
		_tmp4_ = _tmp3_;
		_tmp0_ = _tmp4_ == ((guint) 43);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		gtk_widget_set_sensitive ((GtkWidget*) _data1_->setkeys, TRUE);
	} else {
		gtk_widget_set_sensitive ((GtkWidget*) _data1_->setkeys, FALSE);
	}
}


static void ___lambda4__gtk_editable_changed (GtkEditable* _sender, gpointer self) {
	__lambda4_ (self);
}


static void __lambda5_ (Block1Data* _data1_) {
	bfxconsole* self;
	gboolean _tmp0_ = FALSE;
	guint _tmp1_ = 0U;
	guint _tmp2_ = 0U;
	self = _data1_->self;
	_tmp1_ = gtk_entry_get_text_length (_data1_->apisecret);
	_tmp2_ = _tmp1_;
	if (_tmp2_ == ((guint) 43)) {
		guint _tmp3_ = 0U;
		guint _tmp4_ = 0U;
		_tmp3_ = gtk_entry_get_text_length (_data1_->apikey);
		_tmp4_ = _tmp3_;
		_tmp0_ = _tmp4_ == ((guint) 43);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		gtk_widget_set_sensitive ((GtkWidget*) _data1_->setkeys, TRUE);
	} else {
		gtk_widget_set_sensitive ((GtkWidget*) _data1_->setkeys, FALSE);
	}
}


static void ___lambda5__gtk_editable_changed (GtkEditable* _sender, gpointer self) {
	__lambda5_ (self);
}


static void __lambda6_ (Block1Data* _data1_) {
	bfxconsole* self;
	GSettings* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	GSettings* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	gchar* uri = NULL;
	gchar* _tmp4_ = NULL;
	SoupSession* session = NULL;
	SoupSession* _tmp5_ = NULL;
	SoupMessage* message = NULL;
	SoupMessage* _tmp6_ = NULL;
	self = _data1_->self;
	_tmp0_ = self->priv->settings;
	_tmp1_ = gtk_entry_get_text (_data1_->apikey);
	g_settings_set_string (_tmp0_, "apikey", _tmp1_);
	_tmp2_ = self->priv->settings;
	_tmp3_ = gtk_entry_get_text (_data1_->apisecret);
	g_settings_set_string (_tmp2_, "apisecret", _tmp3_);
	_tmp4_ = g_strdup ("https://api.bitfinex.com/v1");
	uri = _tmp4_;
	_tmp5_ = soup_session_new ();
	session = _tmp5_;
	_tmp6_ = soup_message_new ("GET", uri);
	message = _tmp6_;
	_g_object_unref0 (message);
	_g_object_unref0 (session);
	_g_free0 (uri);
}


static void ___lambda6__gtk_button_clicked (GtkButton* _sender, gpointer self) {
	__lambda6_ (self);
}


void bfxconsole_bfx_settings (bfxconsole* self) {
	Block1Data* _data1_;
	GtkGrid* grid = NULL;
	GtkGrid* _tmp0_ = NULL;
	GtkLabel* _tmp1_ = NULL;
	GtkLabel* _tmp2_ = NULL;
	GtkLabel* _tmp3_ = NULL;
	GtkLabel* _tmp4_ = NULL;
	GtkEntry* _tmp5_ = NULL;
	GtkLabel* _tmp6_ = NULL;
	GtkLabel* _tmp7_ = NULL;
	GtkEntry* _tmp8_ = NULL;
	GtkButton* _tmp9_ = NULL;
	GtkApplicationWindow* _tmp10_ = NULL;
	g_return_if_fail (self != NULL);
	_data1_ = g_slice_new0 (Block1Data);
	_data1_->_ref_count_ = 1;
	_data1_->self = g_object_ref (self);
	_tmp0_ = (GtkGrid*) gtk_grid_new ();
	g_object_ref_sink (_tmp0_);
	_g_object_unref0 (grid);
	grid = _tmp0_;
	_tmp1_ = (GtkLabel*) gtk_label_new (" Please enter your Bitfinex API key details: ");
	g_object_ref_sink (_tmp1_);
	_tmp2_ = _tmp1_;
	gtk_grid_attach (grid, (GtkWidget*) _tmp2_, 1, 1, 3, 1);
	_g_object_unref0 (_tmp2_);
	_tmp3_ = (GtkLabel*) gtk_label_new (" API Key: ");
	g_object_ref_sink (_tmp3_);
	_tmp4_ = _tmp3_;
	gtk_grid_attach (grid, (GtkWidget*) _tmp4_, 1, 2, 1, 1);
	_g_object_unref0 (_tmp4_);
	_tmp5_ = (GtkEntry*) gtk_entry_new ();
	g_object_ref_sink (_tmp5_);
	_g_object_unref0 (_data1_->apikey);
	_data1_->apikey = _tmp5_;
	gtk_grid_attach (grid, (GtkWidget*) _data1_->apikey, 2, 2, 1, 1);
	_tmp6_ = (GtkLabel*) gtk_label_new (" API Secret: ");
	g_object_ref_sink (_tmp6_);
	_tmp7_ = _tmp6_;
	gtk_grid_attach (grid, (GtkWidget*) _tmp7_, 1, 3, 1, 1);
	_g_object_unref0 (_tmp7_);
	_tmp8_ = (GtkEntry*) gtk_entry_new ();
	g_object_ref_sink (_tmp8_);
	_g_object_unref0 (_data1_->apisecret);
	_data1_->apisecret = _tmp8_;
	gtk_grid_attach (grid, (GtkWidget*) _data1_->apisecret, 2, 3, 1, 1);
	_tmp9_ = (GtkButton*) gtk_button_new_with_label ("Ok");
	g_object_ref_sink (_tmp9_);
	_g_object_unref0 (_data1_->setkeys);
	_data1_->setkeys = _tmp9_;
	gtk_widget_set_sensitive ((GtkWidget*) _data1_->setkeys, FALSE);
	gtk_grid_attach (grid, (GtkWidget*) _data1_->setkeys, 1, 4, 2, 1);
	_tmp10_ = self->priv->window;
	g_object_set ((GtkContainer*) _tmp10_, "child", (GtkWidget*) grid, NULL);
	gtk_widget_show_all ((GtkWidget*) grid);
	g_signal_connect_data ((GtkEditable*) _data1_->apikey, "changed", (GCallback) ___lambda4__gtk_editable_changed, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
	g_signal_connect_data ((GtkEditable*) _data1_->apisecret, "changed", (GCallback) ___lambda5__gtk_editable_changed, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
	g_signal_connect_data (_data1_->setkeys, "clicked", (GCallback) ___lambda6__gtk_button_clicked, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
	_g_object_unref0 (grid);
	block1_data_unref (_data1_);
	_data1_ = NULL;
}


static gboolean bfxconsole_apikeys_are_set (bfxconsole* self) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	GSettings* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gboolean _tmp4_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp1_ = self->priv->settings;
	_tmp2_ = g_settings_get_string (_tmp1_, "apikey");
	_tmp3_ = _tmp2_;
	_tmp4_ = g_strcmp0 (_tmp3_, "") == 0;
	_g_free0 (_tmp3_);
	if (_tmp4_) {
		_tmp0_ = TRUE;
	} else {
		GSettings* _tmp5_ = NULL;
		gchar* _tmp6_ = NULL;
		gchar* _tmp7_ = NULL;
		_tmp5_ = self->priv->settings;
		_tmp6_ = g_settings_get_string (_tmp5_, "apisecret");
		_tmp7_ = _tmp6_;
		_tmp0_ = g_strcmp0 (_tmp7_, "") == 0;
		_g_free0 (_tmp7_);
	}
	if (_tmp0_) {
		result = TRUE;
		return result;
	} else {
		result = FALSE;
		return result;
	}
}


static void bfxconsole_real_activate (GApplication* base) {
	bfxconsole * self;
	GtkApplicationWindow* _tmp0_ = NULL;
	GtkApplicationWindow* _tmp1_ = NULL;
	GtkApplicationWindow* _tmp2_ = NULL;
	GtkApplicationWindow* _tmp3_ = NULL;
	GtkApplicationWindow* _tmp4_ = NULL;
	GSettings* _tmp5_ = NULL;
	gboolean _tmp6_ = FALSE;
	self = (bfxconsole*) base;
	_tmp0_ = (GtkApplicationWindow*) gtk_application_window_new ((GtkApplication*) self);
	g_object_ref_sink (_tmp0_);
	_g_object_unref0 (self->priv->window);
	self->priv->window = _tmp0_;
	_tmp1_ = self->priv->window;
	gtk_window_set_default_size ((GtkWindow*) _tmp1_, 100, 100);
	_tmp2_ = self->priv->window;
	gtk_window_set_position ((GtkWindow*) _tmp2_, GTK_WIN_POS_CENTER);
	_tmp3_ = self->priv->window;
	gtk_window_set_title ((GtkWindow*) _tmp3_, "bfxconsole");
	_tmp4_ = self->priv->window;
	gtk_widget_show_all ((GtkWidget*) _tmp4_);
	_tmp5_ = g_settings_new ("org.ascension.bfxconsole");
	_g_object_unref0 (self->priv->settings);
	self->priv->settings = _tmp5_;
	_tmp6_ = bfxconsole_apikeys_are_set (self);
	if (_tmp6_) {
		bfxconsole_bfx_settings (self);
	}
}


gint bfxconsole_main (gchar** args, int args_length1) {
	gint result = 0;
	bfxconsole* app = NULL;
	bfxconsole* _tmp0_ = NULL;
	gchar** _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	gint _tmp2_ = 0;
	_tmp0_ = bfxconsole_new ();
	app = _tmp0_;
	_tmp1_ = args;
	_tmp1__length1 = args_length1;
	_tmp2_ = g_application_run ((GApplication*) app, _tmp1__length1, _tmp1_);
	result = _tmp2_;
	_g_object_unref0 (app);
	return result;
}


int main (int argc, char ** argv) {
#if !GLIB_CHECK_VERSION (2,35,0)
	g_type_init ();
#endif
	return bfxconsole_main (argv, argc);
}


static void bfxconsole_class_init (bfxconsoleClass * klass) {
	bfxconsole_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (bfxconsolePrivate));
	((GApplicationClass *) klass)->activate = bfxconsole_real_activate;
	G_OBJECT_CLASS (klass)->finalize = bfxconsole_finalize;
}


static void bfxconsole_instance_init (bfxconsole * self) {
	self->priv = BFXCONSOLE_GET_PRIVATE (self);
}


static void bfxconsole_finalize (GObject* obj) {
	bfxconsole * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_BFXCONSOLE, bfxconsole);
	_g_object_unref0 (self->priv->settings);
	_g_object_unref0 (self->priv->window);
	G_OBJECT_CLASS (bfxconsole_parent_class)->finalize (obj);
}


GType bfxconsole_get_type (void) {
	static volatile gsize bfxconsole_type_id__volatile = 0;
	if (g_once_init_enter (&bfxconsole_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (bfxconsoleClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bfxconsole_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (bfxconsole), 0, (GInstanceInitFunc) bfxconsole_instance_init, NULL };
		GType bfxconsole_type_id;
		bfxconsole_type_id = g_type_register_static (gtk_application_get_type (), "bfxconsole", &g_define_type_info, 0);
		g_once_init_leave (&bfxconsole_type_id__volatile, bfxconsole_type_id);
	}
	return bfxconsole_type_id__volatile;
}



