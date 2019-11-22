use std::marker::PhantomData;
use std::sync::Arc;

/// A marker type that makes the type !Send.
/// Temporal hack until https://github.com/rust-lang/rust/issues/13231 is resolved.
pub(crate) type Unsendable = PhantomData<Arc<()>>;
