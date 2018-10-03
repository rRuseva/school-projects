
/* WindowClosingAdapter.java */
import java.awt.*;

import java.awt.event.*;

public class textFields extends WindowAdapter {
	private boolean exitSystem;

	public textFields(boolean exitSystem) {
		this.exitSystem = exitSystem;
	}

	public textFields() {
		this(false);
	}

	public void windowClosing(WindowEvent event) {
		event.getWindow().setVisible(false);
		event.getWindow().dispose();
		if (exitSystem) {
			System.exit(0);
		}
	}
}